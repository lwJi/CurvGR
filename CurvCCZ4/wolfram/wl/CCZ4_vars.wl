(* ::Package:: *)

(* CCZ4_vars.wl *)

(* (c) Liwei Ji, 07/2025 *)

(***********************)

(* Evolution Variables *)

(***********************)

dtEvolVarlist =
  GridTensors[
    {dtphi[],                              PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[Phi]"},
    {dtgambO[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)O\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {dttrK[],                              PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)K"},
    {dtexAbO[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)O\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {dttrLtO[i],                           PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)O\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {dtTheta[],                            PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[CapitalTheta]"},
    {dtalpha[],                            PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[Alpha]"},
    {dtbetaO[i],                           PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)O\[Beta]"},
    {dtBO[i],                              PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)OB"}
  ];

EvolVarlist =
  GridTensors[
    {phi[],                              PrintAs -> "\[Phi]"},
    {gambO[-i, -j], Symmetric[{-i, -j}], PrintAs -> "O\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {trK[],                              PrintAs -> "K"},
    {exAbO[-i, -j], Symmetric[{-i, -j}], PrintAs -> "O\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {trLtO[i],                           PrintAs -> "O\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {Theta[],                            PrintAs -> "\[CapitalTheta]"},
    {alpha[],                            PrintAs -> "\[Alpha]"},
    {betaO[i],                           PrintAs -> "O\[Beta]"},
    {BO[i],                              PrintAs -> "OB"}
  ];

(*************************)

(* Other Input Variables *)

(*************************)

dEvolVarlist =
  TileTensors[
    {dphi[-k],                                PrintAs -> "\[PartialD]\[Phi]"},
    {dgambO[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[PartialD]O\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {dtrK[-k],                                PrintAs -> "\[PartialD]K"},
    {dexAbO[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[PartialD]O\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {dtrLtO[-k, i],                           PrintAs -> "\[PartialD]O\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {dTheta[-k],                              PrintAs -> "\[PartialD]\[CapitalTheta]"},
    {dalpha[-k],                              PrintAs -> "\[PartialD]\[Alpha]"},
    {dbetaO[-k, i],                           PrintAs -> "\[PartialD]O\[Beta]"},
    {dBO[-k, i],                              PrintAs -> "\[PartialD]OB"}
  ];

ddEvolVarlist =
  TileTensors[
    {ddphi[-i, -j], Symmetric[{-i, -j}],                              PrintAs -> "\[PartialD]\[PartialD]\[Phi]"},
    {ddgambO[-l, -m, -i, -j], GenSet[Cycles[{1, 2}], Cycles[{3, 4}]], PrintAs -> "\[PartialD]\[PartialD]O\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {ddalpha[-i, -j], Symmetric[{-i, -j}],                            PrintAs -> "\[PartialD]\[PartialD]\[Alpha]"},
    {ddbetaO[-i, -j, k], Symmetric[{-i, -j}],                         PrintAs -> "\[PartialD]\[PartialD]O\[Beta]"}
  ];

TmunuVarlist =
  GridTensors[
    {eTtt[],                          PrintAs -> "\!\(\*SubscriptBox[\(T\), \(tt\)]\)"},
    {eTt[-i],                         PrintAs -> "\!\(\*SubscriptBox[\(T\), \(t\)]\)"},
    {eT[-i, -j], Symmetric[{-i, -j}], PrintAs -> "T"}
  ];

(**************************)

(* Intermediate Variables *)

(**************************)

TetradVarlist =
  TempTensors[
    {eOSvt[i, -j], PrintAs -> "eV"},
    {eOSco[-i, j], PrintAs -> "eC"}
  ];

dTetradVarlist =
  TempTensors[
    {deOSvt[-k, i, -j], PrintAs -> "\[PartialD]eV"},
    {deOSco[-k, -i, j], PrintAs -> "\[PartialD]eC"}
  ];

IntermediateVarlist =
  TempTensors[
    {dlnW[-k], PrintAs -> "\[PartialD]lnW"},
    (* {detinvgamt[], PrintAs -> "1/\!\(\*OverscriptBox[\(\[Gamma]\), \(~\)]\)"}, *)
    {invgamt[i, j], Symmetric[{i, j}], PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(~\)]\)"},
    {invgam[i, j], Symmetric[{i, j}], PrintAs -> "\[Gamma]"},
    {gam[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\[Gamma]"},
    {GtDDD[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(~\)]\)"},
    {GtDDU[-k, -i, j], PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(~\)]\)"},
    {Gt[k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(~\)]\)"},
    {trGtd[i], PrintAs -> "(\!\(\*SubscriptBox[OverscriptBox[\(\[CapitalGamma]\), \(~\)], \(d\)]\))"},
    {dgam[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[PartialD]\[Gamma]"},
    {GamDDD[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[CapitalGamma]"},
    {Gam[k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[CapitalGamma]"},
    {exAtUU[i, j], Symmetric[{i, j}], PrintAs -> "\!\(\*OverscriptBox[\(A\), \(~\)]\)"}
  ];

DDVarlist =
  TempTensors[
    {tDtDW[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(~\)]\)\!\(\*OverscriptBox[\(D\), \(~\)]\)W"},
    {DDalpha[-i, -j], Symmetric[{-i, -j}], PrintAs -> "DD\[Alpha]"}
  ];

RVarlist =
  TempTensors[
    {RtW[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*SuperscriptBox[OverscriptBox[\(R\), \(~\)], \(W\)]\)"},
    {Rt[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(R\), \(~\)]\)"},
    {R[-i, -j], Symmetric[{-i, -j}]},
    {trR[], PrintAs -> "R"}
  ];

(* Matter *)

MatterVarlist =
  TempTensors[
    {rho[], PrintAs -> "\[Rho]"},
    {Sm[-i], PrintAs -> "S"},
    {Ss[-i, -j], Symmetric[{-i, -j}], PrintAs -> "S"},
    {trSs[], PrintAs -> "S"}
  ];

(* Constraints *)

dAtUUVarlist =
  TempTensors[
    {trdexAtUU[i], PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(A\), \(~\)]\)"}
  ];

ConstraintVarlist =
  GridTensors[
    {ZtC[i], PrintAs -> "\!\(\*OverscriptBox[\(Z\), \(~\)]\)"},
    {HC[], PrintAs -> "H"},
    {MtC[i], PrintAs -> "\!\(\*OverscriptBox[\(M\), \(~\)]\)"}
  ];

(************)

(* Constant *)

(************)

DefConstantSymbol[cpi, PrintAs -> "\[Pi]"];

DefConstantSymbol[ckappa1, PrintAs -> "\!\(\*SubscriptBox[\(\[Kappa]\), \(1\)]\)"];

DefConstantSymbol[ckappa2, PrintAs -> "\!\(\*SubscriptBox[\(\[Kappa]\), \(2\)]\)"];

DefConstantSymbol[cmuL, PrintAs -> "\!\(\*SubscriptBox[\(\[Mu]\), \(L\)]\)"];

DefConstantSymbol[cmuS, PrintAs -> "\!\(\*SubscriptBox[\(\[Mu]\), \(S\)]\)"];

DefConstantSymbol[ceta, PrintAs -> "\[Eta]"];

