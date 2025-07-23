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

DefChart[sph, M3, {1, 2, 3}, {ra[], th[], ph[]}, ChartColor -> Blue];

DefBasis[Osph, TangentM3, {1, 2, 3}, BasisColor -> Red];

SetBasisChange[CTensor[{{1, 0, 0}, {0, ra[], 0}, {0, 0, ra[] Sin[th[]]}}, {-sph, Osph}], sph];

ComponentValue[ra[], R];
ComponentValue[th[], T];
ComponentValue[ph[], P];


(**********************************)
(* Define Variables and Equations *)
(**********************************)

<<wl/CCZ4_vars.wl

<<wl/CCZ4_rhs.wl

SetComponents[{ChartName -> Osph}, dtEvolVarlist];
SetComponents[{ChartName -> Osph}, EvolVarlist];
SetComponents[{ChartName -> Osph}, dEvolVarlist];

(* Basis transformation *)

SetEQNDelayed[eps[i_, j_], eps[i, j] // SeparateBasis[Osph] // TraceBasisDummy // ToValues];
SetEQNDelayed[exAb[i_, j_], exAb[i, j] // SeparateBasis[Osph] // TraceBasisDummy // ToValues];
SetEQNDelayed[Lt[i_], Lt[i] // SeparateBasis[Osph] // TraceBasisDummy // ToValues];
SetEQNDelayed[beta[i_], beta[i] // SeparateBasis[Osph] // TraceBasisDummy // ToValues];
SetEQNDelayed[B[i_], B[i] // SeparateBasis[Osph] // TraceBasisDummy // ToValues];

SetEQNDelayed[deps[k_, i_, j_], PDsph[k][eps[i, j] // SeparateBasis[Osph] // TraceBasisDummy // ToValues]];

(******************)
(* Print to Files *)
(******************)

SetOutputFile[FileNameJoin[{Directory[], "CurvCCZ4_set_rhs.hxx"}]];

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

  PrintEquations[{Mode -> "Temp"}, EvolVarlist[[5;;-1]]];
  pr[];
  PrintEquations[{Mode -> "Temp"}, dEvolVarlist[[5;;-1]]];
  pr[];

  pr["  });"];
  pr["});"];
];

Import[FileNameJoin[{Environment["GENERATO"], "codes/CarpetXGPU.wl"}]];
