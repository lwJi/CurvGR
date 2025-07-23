(* ::Package:: *)

(* basis_trans.wl *)

(* (c) Liwei Ji, 07/2025 *)

dOrthRules[coord_, orth_] :=
  Flatten @
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

BasisTrans[coord_, orth_] :=
  Module[{},
    SetEQNDelayed[eps[i_, j_],  eps[i, j]  // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[exAb[i_, j_], exAb[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[Lt[i_],       Lt[i]      // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[beta[i_],     beta[i]    // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[B[i_],        B[i]       // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    
    SetEQNDelayed[deps[k_, i_, j_],  PDOfBasis[coord][k][eps[i, j]  // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dOrthRules[coord, orth]];
    SetEQNDelayed[dexAb[k_, i_, j_], PDOfBasis[coord][k][exAb[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dOrthRules[coord, orth]];
    SetEQNDelayed[dLt[k_, i_],       PDOfBasis[coord][k][Lt[i]      // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dOrthRules[coord, orth]];
    SetEQNDelayed[dbeta[k_, i_],     PDOfBasis[coord][k][beta[i]    // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dOrthRules[coord, orth]];
    SetEQNDelayed[dB[k_, i_],        PDOfBasis[coord][k][B[i]       // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dOrthRules[coord, orth]];
  ];
