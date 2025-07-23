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
  Module[{dorthrules},
    dorthrules = dOrthRules[coord, orth];
    (* variable themselves *)
    SetEQNDelayed[eps[i_, j_],  eps[i, j]  // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[exAb[i_, j_], exAb[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[Lt[i_],       Lt[i]      // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[beta[i_],     beta[i]    // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[B[i_],        B[i]       // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    (* first derivatives *)
    SetEQNDelayed[deps[k_, i_, j_],  PDOfBasis[coord][k][eps[i, j]  // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dorthrules /. trigrules];
    SetEQNDelayed[dexAb[k_, i_, j_], PDOfBasis[coord][k][exAb[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dorthrules /. trigrules];
    SetEQNDelayed[dLt[k_, i_],       PDOfBasis[coord][k][Lt[i]      // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dorthrules /. trigrules];
    SetEQNDelayed[dbeta[k_, i_],     PDOfBasis[coord][k][beta[i]    // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dorthrules /. trigrules];
    SetEQNDelayed[dB[k_, i_],        PDOfBasis[coord][k][B[i]       // SeparateBasis[orth] // TraceBasisDummy // ToValues] /. dorthrules /. trigrules];
    (* second derivatives *)
    SetEQNDelayed[ddeps[k_, l_, i_, j_], PDOfBasis[coord][k][PDOfBasis[coord][l][eps[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues]] /. dorthrules /. trigrules];
    SetEQNDelayed[ddbeta[k_, l_, i_],    PDOfBasis[coord][k][PDOfBasis[coord][l][beta[i]   // SeparateBasis[orth] // TraceBasisDummy // ToValues]] /. dorthrules /. trigrules];
  ];
