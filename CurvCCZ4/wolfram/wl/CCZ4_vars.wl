(* ::Package:: *)

(* CCZ4_vars.wl *)

(* (c) Liwei Ji, 07/2025 *)

(***********************)

(* Evolution Variables *)

(***********************)

dtEvolVarlist =
  GridTensors[
    {dtphi[],                              PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[Phi]"},
    {dtepsO[-i, -j], Symmetric[{-i, -j}],  PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)O\[Epsilon]"},
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
    {epsO[-i, -j], Symmetric[{-i, -j}],  PrintAs -> "O\[Epsilon]"},
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
    {depsO[-k, -i, -j], Symmetric[{-i, -j}],  PrintAs -> "\[PartialD]O\[Epsilon]"},
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
    {ddepsO[-l, -m, -i, -j], GenSet[Cycles[{1, 2}], Cycles[{3, 4}]],  PrintAs -> "\[PartialD]\[PartialD]O\[Epsilon]"},
    {ddalpha[-i, -j], Symmetric[{-i, -j}],                            PrintAs -> "\[PartialD]\[PartialD]\[Alpha]"},
    {ddbetaO[-i, -j, k], Symmetric[{-i, -j}],                         PrintAs -> "\[PartialD]\[PartialD]O\[Beta]"}
  ];

TmunuVarlist =
  GridTensors[
    {eTtt[],                          PrintAs -> "\!\(\*SubscriptBox[\(T\), \(tt\)]\)"},
    {eTt[-i],                         PrintAs -> "\!\(\*SubscriptBox[\(T\), \(t\)]\)"},
    {eT[-i, -j], Symmetric[{-i, -j}], PrintAs -> "T"}
  ];

TetradVarlist =
  TempTensors[
    {eOSvt[i, -j],                         PrintAs -> "eV"},
    {eOSco[-i, j],                         PrintAs -> "eC"},
    {gamh[-i, -j], Symmetric[{-i, -j}],    PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(^\)]\)"},
    {detgamh[],                            PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(^\)]\)"},
    {Gamh[k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(^\)]\)"}
  ];

dTetradVarlist =
  TempTensors[
    {deOSvt[-k, i, -j],                                   PrintAs -> "\[PartialD]eV"},
    {deOSco[-k, -i, j],                                   PrintAs -> "\[PartialD]eC"},
    {ddeOSvt[-k, -l, i, -j], Symmetric[{-k, -l}],         PrintAs -> "\[PartialD]\[PartialD]eV"},
    {deeOSco[-k, -i, m, -j, n],                           PrintAs -> "\[PartialD]eCeC"},
    {ddeeOSco[-k, -l, -i, m, -j, n], Symmetric[{-k, -l}], PrintAs -> "\[PartialD]\[PartialD]eCeC"},
    {dgamh[-k, -i, -j], Symmetric[{-i, -j}],              PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(\[Gamma]\), \(^\)]\)"},
    {ddetgamh[-k],                                        PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(\[Gamma]\), \(^\)]\)"},
    {dGamh[-k, l, -i, -j], Symmetric[{-i, -j}],           PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(^\)]\)"}
  ];

(**************************)

(* Intermediate Variables *)

(**************************)

TempEvolVarlist =
  TempTensors[
    {eps[-i, -j], Symmetric[{-i, -j}],  PrintAs -> "\[Epsilon]"},
    {gamb[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {exAb[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {trLt[i],                           PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {beta[i],                           PrintAs -> "\[Beta]"},
    {B[i],                              PrintAs -> "B"}
  ];

TempdEvolVarlist =
  TempTensors[
    (* first *)
    {deps[-k, -i, -j], Symmetric[{-i, -j}],  PrintAs -> "\[PartialD]\[Epsilon]"},
    {dgamb[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {dexAb[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {dtrLt[-k, i],                           PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {dbeta[-k, i],                           PrintAs -> "\[PartialD]\[Beta]"},
    {dB[-k, i],                              PrintAs -> "\[PartialD]B"},
    (* second *)
    {ddeps[-l, -m, -i, -j], GenSet[Cycles[{1, 2}], Cycles[{3, 4}]], PrintAs -> "\[PartialD]\[PartialD]\[Epsilon]"},
    {ddbeta[-i, -j, k], Symmetric[{-i, -j}],                        PrintAs -> "\[PartialD]\[PartialD]\[Beta]"}
  ];

IntermediateVarlist =
  TempTensors[
    {psim4[],                                   PrintAs -> "\!\(\*SuperscriptBox[\(\[Psi]\), \(-4\)]\)"},
    {psi4[],                                    PrintAs -> "\!\(\*SuperscriptBox[\(\[Psi]\), \(4\)]\)"},
    {dgam[-k, -i, -j], Symmetric[{-i, -j}],     PrintAs -> "\[PartialD]\[Gamma]"},
    {invgamb[i, j], Symmetric[{i, j}],          PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {invgam[i, j], Symmetric[{i, j}],           PrintAs -> "\[Gamma]"},
    {gam[-i, -j], Symmetric[{-i, -j}],          PrintAs -> "\[Gamma]"},
    {GambDDD[-k, -i, -j], Symmetric[{-i, -j}],  PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(_\)]\)"},
    {Gamb[k, -i, -j], Symmetric[{-i, -j}],      PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(_\)]\)"},
    {GamDDD[-k, -i, -j], Symmetric[{-i, -j}],   PrintAs -> "\[CapitalGamma]"},
    {Gam[k, -i, -j], Symmetric[{-i, -j}],       PrintAs -> "\[CapitalGamma]"}
  ];

bDVarlist =
  TempTensors[
    {trbDbeta[], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Beta]"}
  ];

bDbDVarlist =
  TempTensors[
    {bDbDphi[-i, -j], Symmetric[{-i, -j}],   PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Phi]"},
    {bDbDalpha[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Alpha]"}
  ];

hDVarlist =
  TempTensors[
    {hDgamb[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {hDtrLt[-k, i],                           PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {hDbeta[-k, i],                           PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\[Beta]"}
  ];

hDhDVarlist =
  TempTensors[
    {dhDgamb[-l, -m, -i, -j], GenSet[Cycles[{1, 2}], Cycles[{3, 4}]],  PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {hDhDgamb[-l, -m, -i, -j], GenSet[Cycles[{1, 2}], Cycles[{3, 4}]], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {hDhDbeta[-i, -j, k], Symmetric[{-i, -j}],                         PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(D\), \(^\)]\)\[Beta]"}
  ];

DGamVarlist =
  TempTensors[
    {DGamDDD[-k, -i, -j], Symmetric[{-i, -j}],  PrintAs -> "\[CapitalDelta]\[CapitalGamma]"},
    {DGam[k, -i, -j], Symmetric[{-i, -j}],      PrintAs -> "\[CapitalDelta]\[CapitalGamma]"},
    {trDGam[k],                                 PrintAs -> "\[CapitalDelta]\[CapitalGamma]"}
  ];

RVarlist =
  TempTensors[
    {RZ[-i, -j], Symmetric[{-i, -j}],       PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(Z4\)]\)"},
    {Rb[-i, -j], Symmetric[{-i, -j}],       PrintAs -> "\!\(\*OverscriptBox[\(R\), \(_\)]\)"},
    {RbTF[-i, -j], Symmetric[{-i, -j}],     PrintAs -> "\!\(\*SuperscriptBox[OverscriptBox[\(R\), \(_\)], \(TF\)]\)"},
    {Rphi[-i, -j], Symmetric[{-i, -j}],     PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(\[Phi]\)]\)"},
    {RphiTF[-i, -j], Symmetric[{-i, -j}],   PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(\[Phi]TF\)]\)"},
    {Ralpha[-i, -j], Symmetric[{-i, -j}],   PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(\[Alpha]\)]\)"},
    {RalphaTF[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(\[Alpha]TF\)]\)"}
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

