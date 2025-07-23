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

DefChart[Sph, M3, {1, 2, 3}, {rad[], th[], ph[]}, ChartColor -> Blue];

DefChart[Orth, M3, {1, 2, 3}, {radO[], thO[], phO[]}, ChartColor -> Red];

ComponentValue[rad[], corad];
ComponentValue[th[], coth];
ComponentValue[ph[], coph];


(**********************************)
(* Define Variables and Equations *)
(**********************************)

<<wl/CCZ4_vars.wl

<<wl/CCZ4_rhs.wl

SetComponents[{ChartName -> Orth}, dtEvolVarlist];

(******************)
(* Print to Files *)
(******************)

SetOutputFile[FileNameJoin[{Directory[], "CurvCCZ4_set_rhs.hxx"}]];

SetMainPrint[
  (* Initialize grid function names *)
  PrintInitializations[{Mode -> "MainOut", ChartName -> Orth}, dtEvolVarlist];
  pr[];

  (* Loops *)
  pr["noinline([&]() __attribute__((__flatten__, __hot__)) {"];
  pr["grid.loop_int_device<0, 0, 0>("];
  pr["  grid.nghostzones, [=] ARITH_DEVICE(const PointDesc &p) ARITH_INLINE {"];
  pr["const int ijk = layout2.linear(p.i, p.j, p.k);"];
  pr[];
  pr["const auto coX = p.x;"];
  pr["const auto coY = p.y;"];
  pr["const auto coZ = p.z;"];
  pr[];

  (*
  PrintInitializations[{Mode -> "Derivs", DerivsOrder -> 1},
                       dEvolVarlist];
  pr[];

  PrintEquations[{Mode -> "Temp"}, IntermediateVarlist];
  pr[];
  *)

  pr["  });"];
  pr["});"];
];

Import[FileNameJoin[{Environment["GENERATO"], "codes/CarpetXGPU.wl"}]];
