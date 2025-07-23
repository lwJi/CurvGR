(* ::Package:: *)

(* Osph_rules.wl *)

(* (c) Liwei Ji, 07/2025 *)

dOsphRules =
  Flatten @
    Module[{TDDs = {"eps", "exAb"}, VUs = {"Lt", "beta", "B"}},
      {
        Table[
          PDsph[{kk, -sph}][ToExpression[TDDs[[vv]] <> "Osph" <> ToString[ii] <> ToString[jj]]]
            -> ToExpression["d" <> TDDs[[vv]] <> "Osph" <> ToString[kk] <> ToString[ii] <> ToString[jj]],
        {vv, 1, 2}, {kk, 1, 3}, {ii, 1, 3}, {jj, ii, 3}],
        Table[
          PDsph[{kk, -sph}][ToExpression[VUs[[vv]] <> "Osph" <> ToString[ii]]]
            -> ToExpression["d" <> VUs[[vv]] <> "Osph" <> ToString[kk] <> ToString[ii]],
        {vv, 1, 3}, {kk, 1, 3}, {ii, 1, 3}]}
    ]
