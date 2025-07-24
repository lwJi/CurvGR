(* ::Package:: *)

(* basis_transformation.wl *)

(* (c) Liwei Ji, 07/2025 *)

(**
 * \brief Replace PD with symbols (ORDER Matters)
 *
 * \param coord  coordinate basis
 * \param orth   orthonormal basis
 *)
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

(**
 * \brief Apply basis transformation from orthonormal basis to coordinate basis for the evolution variables and its coordinate derivatives
 *
 * \param coord  coordinate basis
 * \param orth   orthonormal basis
 *)
TransEvolOrthToCoord[orth_, coord_] :=
  Module[{rules},
    rules = dOrthRules[coord, orth];
    (* variable themselves *)
    SetEQNDelayed[eps[i_, j_],  eps[i, j]  // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[exAb[i_, j_], exAb[i, j] // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[Lt[i_],       Lt[i]      // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[beta[i_],     beta[i]    // SeparateBasis[orth] // TraceBasisDummy // ToValues];
    SetEQNDelayed[B[i_],        B[i]       // SeparateBasis[orth] // TraceBasisDummy // ToValues];
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

(**
 * \brief Apply basis transformation from coordinate basis to orthonormal basis for the RHS of evolution variables
 *
 * \param coord  coordinate basis
 * \param orth   orthonormal basis
 *)
TransEvolRHSCoordToOrth[coord_, orth_] :=
  Module[{},
    SetEQNDelayed[{SuffixName -> "Orth"}, dteps[i_, j_],  dteps[i, j]  // SeparateBasis[coord] // TraceBasisDummy // ToValues];
    SetEQNDelayed[{SuffixName -> "Orth"}, dtexAb[i_, j_], dtexAb[i, j] // SeparateBasis[coord] // TraceBasisDummy // ToValues];
    SetEQNDelayed[{SuffixName -> "Orth"}, dtLt[i_],       dtLt[i]      // SeparateBasis[coord] // TraceBasisDummy // ToValues];
    SetEQNDelayed[{SuffixName -> "Orth"}, dtbeta[i_],     dtbeta[i]    // SeparateBasis[coord] // TraceBasisDummy // ToValues];
    SetEQNDelayed[{SuffixName -> "Orth"}, dtB[i_],        dtB[i]       // SeparateBasis[coord] // TraceBasisDummy // ToValues];
  ];

