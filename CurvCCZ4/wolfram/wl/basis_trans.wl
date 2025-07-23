(* ::Package:: *)

(* basis_trans.wl *)

(* (c) Liwei Ji, 07/2025 *)

(* Replace PD with symbols: order matters *)
dOrthRules[coord_, orth_] :=
  Flatten @
    Module[{TDDs = {"eps", "exAb"}, VUs = {"Lt", "beta", "B"}},
      {
        (* 2 rank tensors: d_k d_l T_{ij} *)
        Table[PDOfBasis[coord][{kk, -coord}][PDOfBasis[coord][{ll, -coord}][
                      ToExpression[TDDs[[vv]] <> ToString[orth] <> ToString[ii] <> ToString[jj] <> GetGridPointIndex[]]]] ->
              ToExpression["dd" <> TDDs[[vv]] <> ToString[orth] <> ToString[kk] <> ToString[ll] <> ToString[ii] <> ToString[jj] <> GetTilePointIndex[]],
        {vv, 1, 2}, {kk, 1, 3}, {ll, kk, 3}, {ii, 1, 3}, {jj, ii, 3}],
        (* 2 rank tensors: d_k T_{ij} *)
        Table[PDOfBasis[coord][{kk, -coord}][
                     ToExpression[TDDs[[vv]] <> ToString[orth] <> ToString[ii] <> ToString[jj] <> GetGridPointIndex[]]] ->
              ToExpression["d" <> TDDs[[vv]] <> ToString[orth] <> ToString[kk] <> ToString[ii] <> ToString[jj] <> GetTilePointIndex[]],
        {vv, 1, 2}, {kk, 1, 3}, {ii, 1, 3}, {jj, ii, 3}],
        (* 1 rank vectors: d_k d_l V_i *)
        Table[PDOfBasis[coord][{kk, -coord}][PDOfBasis[coord][{ll, -coord}][
                      ToExpression[VUs[[vv]] <> ToString[orth] <> ToString[ii] <> GetGridPointIndex[]]]] ->
              ToExpression["dd" <> VUs[[vv]] <> ToString[orth] <> ToString[kk] <> ToString[ll] <> ToString[ii] <> GetTilePointIndex[]],
        {vv, 1, 3}, {kk, 1, 3}, {ll, kk, 3}, {ii, 1, 3}],
        (* 1 rank vectors: d_k V_i *)
        Table[PDOfBasis[coord][{kk, -coord}][
                     ToExpression[VUs[[vv]] <> ToString[orth] <> ToString[ii] <> GetGridPointIndex[]]] ->
              ToExpression["d" <> VUs[[vv]] <> ToString[orth] <> ToString[kk] <> ToString[ii] <> GetTilePointIndex[]],
        {vv, 1, 3}, {kk, 1, 3}, {ii, 1, 3}]
      }
    ];

BasisTrans[coord_, orth_, trigrules_] :=
  Module[{rules},
    rules = Join[dOrthRules[coord, orth], trigrules]; (* order matters *)
    (* variable themselves *)
    SetEQNDelayed[eps[i_, j_],  (eps[i, j]  // SeparateBasis[orth] // TraceBasisDummy // ToValues) /. trigrules];
    SetEQNDelayed[exAb[i_, j_], (exAb[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues) /. trigrules];
    SetEQNDelayed[Lt[i_],       (Lt[i]      // SeparateBasis[orth] // TraceBasisDummy // ToValues) /. trigrules];
    SetEQNDelayed[beta[i_],     (beta[i]    // SeparateBasis[orth] // TraceBasisDummy // ToValues) /. trigrules];
    SetEQNDelayed[B[i_],        (B[i]       // SeparateBasis[orth] // TraceBasisDummy // ToValues) /. trigrules];
    (* first derivatives *)
    SetEQNDelayed[deps[k_, i_, j_],  PDOfBasis[coord][k][eps[i, j]  // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. rules];
    SetEQNDelayed[dexAb[k_, i_, j_], PDOfBasis[coord][k][exAb[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. rules];
    SetEQNDelayed[dLt[k_, i_],       PDOfBasis[coord][k][Lt[i]      // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. rules];
    SetEQNDelayed[dbeta[k_, i_],     PDOfBasis[coord][k][beta[i]    // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. rules];
    SetEQNDelayed[dB[k_, i_],        PDOfBasis[coord][k][B[i]       // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. rules];
    (* second derivatives *)
    SetEQNDelayed[ddeps[k_, l_, i_, j_], PDOfBasis[coord][k][PDOfBasis[coord][l][eps[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues]] /. rules];
    SetEQNDelayed[ddbeta[k_, l_, i_],    PDOfBasis[coord][k][PDOfBasis[coord][l][beta[i]   // SeparateBasis[orth] // TraceBasisDummy // ToValues]] /. rules];
  ];
