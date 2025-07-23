(* ::Package:: *)

(* reference_metric.wl *)

(* (c) Liwei Ji, 07/2025 *)

(****************************************************)

(* Set Reference Metric related quantities directly *)

(****************************************************)

SetRefMetrics[coord_] :=
  Module[{},
    IndexSetDelayed[gamhdet[],             Determinant[gamh, coord][]];
    IndexSetDelayed[dgamhdet[k_],          PDOfBasis[coord][k][Determinant[gamh, coord][]]                      // DummyToBasis[coord] // TraceBasisDummy // ToValues];
    IndexSetDelayed[ddgamhdet[k_, l_],     PDOfBasis[coord][k][PDOfBasis[coord][l][Determinant[gamh, coord][]]] // DummyToBasis[coord] // TraceBasisDummy // ToValues];
    IndexSetDelayed[dgamh[k_, i_, j_],     PDOfBasis[coord][k][gamh[i, j]]                                      // DummyToBasis[coord] // TraceBasisDummy // ToValues];
    IndexSetDelayed[Gamh[k_, i_, j_],      Christoffel[cdh, PDOfBasis[coord]][k, i, j]];
    IndexSetDelayed[dGamh[k_, l_, i_, j_], PDOfBasis[coord][k][Christoffel[cdh, PDOfBasis[coord]][l, i, j]]];
  ];

