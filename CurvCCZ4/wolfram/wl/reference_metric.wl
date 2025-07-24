(* ::Package:: *)

(* reference_metric.wl *)

(* (c) Liwei Ji, 07/2025 *)

(****************************************************)

(* Set Reference Metric related quantities directly *)

(****************************************************)

SetRefMetrics[coord_, trigrules_] :=
  Module[{},
    IndexSetDelayed[gamhdet[],             Determinant[gamh, coord][]                                            /. trigrules];
    IndexSetDelayed[dgamhdet[k_],          (PDOfBasis[coord][k][Determinant[gamh, coord][]]                      // DummyToBasis[coord] // TraceBasisDummy // ToValues) /. trigrules];
    IndexSetDelayed[ddgamhdet[k_, l_],     (PDOfBasis[coord][k][PDOfBasis[coord][l][Determinant[gamh, coord][]]] // DummyToBasis[coord] // TraceBasisDummy // ToValues) /. trigrules];
    IndexSetDelayed[dgamh[k_, i_, j_],     (PDOfBasis[coord][k][gamh[i, j]]                                      // DummyToBasis[coord] // TraceBasisDummy // ToValues) /. trigrules];
    IndexSetDelayed[Gamh[k_, i_, j_],      Christoffel[cdh, PDOfBasis[coord]][k, i, j]                           /. trigrules];
    IndexSetDelayed[dGamh[k_, l_, i_, j_], PDOfBasis[coord][k][Christoffel[cdh, PDOfBasis[coord]][l, i, j]]      /. trigrules];
  ];

