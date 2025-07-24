(* ::Package:: *)

(* CurvCCZ4_set_rhs.wl *)

(* (c) Liwei Ji, 07/2025 *)

(******************)
(* Configurations *)
(******************)

Needs["xAct`xCoba`", FileNameJoin[{Environment["GENERATO"], "src/Generato.wl"}]]

SetPVerbose[False];

SetPrintDate[False];

SetGridPointIndex["[[ijk]]"];

(*SetUseLetterForTensorComponet[True];*)

SetTempVariableType["auto"];

DefManifold[M3, 3, IndexRange[a, z]];

(************************)
(* Basis Transformation *)
(************************)

(* Default Chart *)
DefChart[sph, M3, {1, 2, 3}, {ra[], th[], ph[]}, ChartColor -> Blue];

(* Osphonormal Basis adapted to the Default Chart. *)
DefBasis[Osph, TangentM3, {1, 2, 3}, BasisColor -> Red];

SetBasisChange[CTensor[{{1, 0, 0}, {0, ra[], 0}, {0, 0, ra[] Sin[th[]]}}, {-sph, Osph}], sph];

(****************************************************)
(* Set Reference Metric related quantities directly *)
(****************************************************)

<<wl/reference_metric.wl

DefMetric[1, gamh[-i, -j], cdh,
  SymbolOfCovD -> {"|", "\!\(\*OverscriptBox[\(D\), \(^\)]\)"},
  PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(^\)]\)"
];

MetricInBasis[gamh, -sph, DiagonalMatrix[{1, ra[]^2, ra[]^2 Sin[th[]]^2}]];

MetricCompute[gamh, sph, All, Parallelize -> True, Verbose -> False]

SetRefMetrics[sph];

(**********************************)
(* Define Variables and Equations *)
(**********************************)

<<wl/basis_transformation.wl

<<wl/CCZ4_vars.wl

(* set components in orthonormal basis, components in default basis are set automatically *)
SetComponents[{ChartName -> Osph}, dtEvolVarlist];
SetComponents[{ChartName -> Osph}, EvolVarlist];

<<wl/CCZ4_rhs.wl

(* basis transformation *)
BasisTrans[sph, Osph];

(* set invgamb *)
Module[{Mat, invMat},
  Mat =
    Table[gamb[{ii, -sph}, {jj, -sph}] // ToValues, {ii, 1, 3}, {jj, 1, 3}];
  invMat = Inverse[Mat] /. {1 / Det[Mat] -> invgambdet[]};
  SetEQNDelayed[invgambdet[], 1 / gamhdet[]];
  SetEQNDelayed[invgamb[i_, j_], invMat[[i[[1]], j[[1]]]] // Simplify]
];

(******************)
(* Print to Files *)
(******************)

SetOutputFile[FileNameJoin[{Directory[], "CurvCCZ4_set_rhs.hxx"}]];

ComponentValue[ra[], R];
ComponentValue[th[], T];
ComponentValue[ph[], P];

trigrules = {
  Sin[T] -> sinth,
  Cos[T] -> costh,
  Csc[T] -> cscth,
  Cot[T] -> cotth,
  Cos[2 T] -> cos2th
};

SetMainPrint[
  (* Initialize grid function names *)
  PrintInitializations[{Mode -> "MainOut", ChartName -> Osph}, dtEvolVarlist];
  pr[];
  PrintInitializations[{Mode -> "MainIn", ChartName -> Osph}, EvolVarlist];
  pr[];

  (* Loops *)
  pr["noinline([&]() __attribute__((__flatten__, __hot__)) {"];
  pr["grid.loop_int_device<0, 0, 0>("];
  pr["  grid.nghostzones, [=] ARITH_DEVICE(const PointDesc &p) ARITH_INLINE {"];
  pr["const int ijk = layout2.linear(p.i, p.j, p.k);"];
  pr[];
  pr["const auto R = p.x;"];
  pr["const auto T = p.y;"];
  pr["const auto P = p.z;"];
  pr[];

  (*
  PrintInitializations[{Mode -> "Derivs", DerivsOrder -> 1},
                       dEvolVarlist];
  pr[];
  *)

  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, EvolVarlist[[5;;-1]]];
  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, dEvolVarlist[[5;;-1]]];
  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, ddEvolVarlist[[3;;-1]]];
  pr[];

  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, IntermediateVarlist];
  pr[];

  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, bDVarlist];
  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, bDbDVarlist];
  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, trVarlist];
  pr[];

  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, hDVarlist];
  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, hDhDVarlist];
  pr[];

  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, DGamVarlist];
  pr[];

  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, RVarlist];
  pr[];

  PrintEquations[{Mode -> "Temp", ExtraReplaceRules -> trigrules}, LieVarlist];
  pr[];

  pr["  });"];
  pr["});"];
];

Import[FileNameJoin[{Environment["GENERATO"], "codes/CarpetXGPU.wl"}]];
