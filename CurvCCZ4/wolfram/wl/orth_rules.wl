(* ::Package:: *)

(* Orth_rules.wl *)

(* (c) Liwei Ji, 07/2025 *)

dOrthRules[coord_, orth_] := Flatten @
  Module[{TDDs = {"eps", "exAb"}, VUs = {"Lt", "beta", "B"}},
    {
      (* 2 rank tensors *)
      Table[PDOfBasis[coord][{kk, -coord}][ToExpression[TDDs[[vv]] <> ToString[orth] <> ToString[ii] <> ToString[jj] <> GetGridPointIndex[]]] ->
                                    ToExpression["d" <> TDDs[[vv]] <> ToString[orth] <> ToString[kk] <> ToString[ii] <> ToString[jj] <> GetTilePointIndex[]],
      {vv, 1, 2}, {kk, 1, 3}, {ii, 1, 3}, {jj, ii, 3}],
      (* 1 rank vectors *)
      Table[PDOfBasis[coord][{kk, -coord}][ToExpression[VUs[[vv]] <> ToString[orth] <> ToString[ii] <> GetGridPointIndex[]]] ->
                                    ToExpression["d" <> VUs[[vv]] <> ToString[orth] <> ToString[kk] <> ToString[ii] <> GetTilePointIndex[]],
      {vv, 1, 3}, {kk, 1, 3}, {ii, 1, 3}]
    }
  ];
