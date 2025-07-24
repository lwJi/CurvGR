(* ::Package:: *)

(* CCZ4_vars.wl *)

(* (c) Liwei Ji, 07/2025 *)

(***********************)

(* Evolution Variables *)

(***********************)

EvolVarlist =
  GridTensors[
    (* scalars *)
    {phi[],                             PrintAs -> "\[Phi]"},
    {trK[],                             PrintAs -> "K"},
    {Theta[],                           PrintAs -> "\[CapitalTheta]"},
    {alpha[],                           PrintAs -> "\[Alpha]"},
    (* non-scalars *)
    {eps[-i, -j], Symmetric[{-i, -j}],  PrintAs -> "\[Epsilon]"},
    {exAb[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {Lt[i],                             PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {beta[i],                           PrintAs -> "\[Beta]"},
    {B[i],                              PrintAs -> "B"}
  ];

dtEvolVarlist =
  GridTensors[
    (* scalars *)
    {dtphi[],                             PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[Phi]"},
    {dttrK[],                             PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)K"},
    {dtTheta[],                           PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[CapitalTheta]"},
    {dtalpha[],                           PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[Alpha]"},
    (* non-scalars *)
    {dteps[-i, -j], Symmetric[{-i, -j}],  PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[Epsilon]"},
    {dtexAb[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {dtLt[i],                             PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {dtbeta[i],                           PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)\[Beta]"},
    {dtB[i],                              PrintAs -> "\!\(\*SubscriptBox[\(\[PartialD]\), \(t\)]\)B"}
  ];

(*************************)

(* Other Input Variables *)

(*************************)

dEvolVarlist =
  TileTensors[
    (* scalars *)
    {dphi[-k],                               PrintAs -> "\[PartialD]\[Phi]"},
    {dtrK[-k],                               PrintAs -> "\[PartialD]K"},
    {dTheta[-k],                             PrintAs -> "\[PartialD]\[CapitalTheta]"},
    {dalpha[-k],                             PrintAs -> "\[PartialD]\[Alpha]"},
    (* non-scalars *)
    {deps[-k, -i, -j], Symmetric[{-i, -j}],  PrintAs -> "\[PartialD]\[Epsilon]"},
    {dexAb[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {dLt[-k, i],                             PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {dbeta[-k, i],                           PrintAs -> "\[PartialD]\[Beta]"},
    {dB[-k, i],                              PrintAs -> "\[PartialD]B"}
  ];

ddEvolVarlist =
  TileTensors[
    (* scalars *)
    {ddphi[-i, -j], Symmetric[{-i, -j}],                            PrintAs -> "\[PartialD]\[PartialD]\[Phi]"},
    {ddalpha[-i, -j], Symmetric[{-i, -j}],                          PrintAs -> "\[PartialD]\[PartialD]\[Alpha]"},
    (* non-scalars *)
    {ddeps[-l, -m, -i, -j], GenSet[Cycles[{1, 2}], Cycles[{3, 4}]], PrintAs -> "\[PartialD]\[PartialD]\[Epsilon]"},
    {ddbeta[-i, -j, k], Symmetric[{-i, -j}],                        PrintAs -> "\[PartialD]\[PartialD]\[Beta]"}
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

IntermediateVarlist =
  TempTensors[
    {gamb[-i, -j], Symmetric[{-i, -j}],        PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {dgamb[-k, -i, -j], Symmetric[{-i, -j}],   PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {psim4[],                                  PrintAs -> "\!\(\*SuperscriptBox[\(\[Psi]\), \(-4\)]\)"},
    {psi4[],                                   PrintAs -> "\!\(\*SuperscriptBox[\(\[Psi]\), \(4\)]\)"},
    {dgam[-k, -i, -j], Symmetric[{-i, -j}],    PrintAs -> "\[PartialD]\[Gamma]"},
    {invgambdet[],                             PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {invgamb[i, j], Symmetric[{i, j}],         PrintAs -> "\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {invgam[i, j], Symmetric[{i, j}],          PrintAs -> "\[Gamma]"},
    {gam[-i, -j], Symmetric[{-i, -j}],         PrintAs -> "\[Gamma]"},
    {GambDDD[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(_\)]\)"},
    {Gamb[k, -i, -j], Symmetric[{-i, -j}],     PrintAs -> "\!\(\*OverscriptBox[\(\[CapitalGamma]\), \(_\)]\)"},
    {GamDDD[-k, -i, -j], Symmetric[{-i, -j}],  PrintAs -> "\[CapitalGamma]"},
    {Gam[k, -i, -j], Symmetric[{-i, -j}],      PrintAs -> "\[CapitalGamma]"},
    {exAbUU[i, j], Symmetric[{i, j}],          PrintAs -> "\!\(\*OverscriptBox[\(A\), \(_\)]\)"}
  ];

bDVarlist =
  TempTensors[
    {trbDbeta[],     PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Beta]"},
    {bDtrbDbeta[-i], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Beta]"}
  ];

bDbDVarlist =
  TempTensors[
    {bDbDphi[-i, -j], Symmetric[{-i, -j}],   PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Phi]"},
    {bDbDalpha[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Alpha]"}
  ];

trVarlist =
  TempTensors[
    {trexAb[],       PrintAs -> "\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {trbDbDphi[],    PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Phi]"},
    {trbDphibDphi[], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Phi]\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Phi]"},
    {trbDbDalpha[],  PrintAs -> "\!\(\*OverscriptBox[\(D\), \(_\)]\)\!\(\*OverscriptBox[\(D\), \(_\)]\)\[Alpha]"}
  ];

hDVarlist =
  TempTensors[
    {hDgamb[-k, -i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {hDLt[-k, i],                             PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {hDbeta[-k, i],                           PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\[Beta]"},
    {hDB[-k, i],                              PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)B"}
  ];

(**
 * Here dhDgamb is not symmetric in the first two index. However, hDhDgamb is,
 * so in the calculation it only require 'half' of the components of dhDgamb.
 * So here we can effectively define dhDgamb as symmetric in {k, l}.
 *)
hDhDVarlist =
  TempTensors[
    {dhDgamb[-k, -l, -i, -j], GenSet[Cycles[{1, 2}], Cycles[{3, 4}]],  PrintAs -> "\[PartialD]\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {hDhDgamb[-k, -l, -i, -j], GenSet[Cycles[{1, 2}], Cycles[{3, 4}]], PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {hDhDbeta[-i, -j, k], Symmetric[{-i, -j}],                         PrintAs -> "\!\(\*OverscriptBox[\(D\), \(^\)]\)\!\(\*OverscriptBox[\(D\), \(^\)]\)\[Beta]"}
  ];

DGamVarlist =
  TempTensors[
    {DGamDDD[-k, -i, -j], Symmetric[{-i, -j}],  PrintAs -> "\[CapitalDelta]\[CapitalGamma]"},
    {DGam[k, -i, -j], Symmetric[{-i, -j}],      PrintAs -> "\[CapitalDelta]\[CapitalGamma]"},
    {trDGam[k],                                 PrintAs -> "\[CapitalDelta]\[CapitalGamma]"},
    {ZU[i],                                     PrintAs -> "Z"},
    {ZD[-i],                                    PrintAs -> "Z"}
  ];

RVarlist =
  TempTensors[
    {RZ[-i, -j], Symmetric[{-i, -j}],       PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(Z4\)]\)"},
    {Rb[-i, -j], Symmetric[{-i, -j}],       PrintAs -> "\!\(\*OverscriptBox[\(R\), \(_\)]\)"},
    {trRb[],                                PrintAs -> "\!\(\*OverscriptBox[\(R\), \(_\)]\)"},
    {RbTF[-i, -j], Symmetric[{-i, -j}],     PrintAs -> "\!\(\*SuperscriptBox[OverscriptBox[\(R\), \(_\)], \(TF\)]\)"},
    {Rphi[-i, -j], Symmetric[{-i, -j}],     PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(\[Phi]\)]\)"},
    {RphiTF[-i, -j], Symmetric[{-i, -j}],   PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(\[Phi]TF\)]\)"},
    {Ralpha[-i, -j], Symmetric[{-i, -j}],   PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(\[Alpha]\)]\)"},
    {RalphaTF[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*SuperscriptBox[\(R\), \(\[Alpha]TF\)]\)"}
  ];

LieVarlist =
  TempTensors[
    (* scalars *)
    {Lbetaphi[],                             PrintAs -> "\!\(\*SubscriptBox[\(\[ScriptCapitalL]\), \(\[Beta]\)]\)\[Phi]"},
    {LbetatrK[],                             PrintAs -> "\!\(\*SubscriptBox[\(\[ScriptCapitalL]\), \(\[Beta]\)]\)K"},
    {LbetaTheta[],                           PrintAs -> "\!\(\*SubscriptBox[\(\[ScriptCapitalL]\), \(\[Beta]\)]\)\[CapitalTheta]"},
    {Lbetaalpha[],                           PrintAs -> "\!\(\*SubscriptBox[\(\[ScriptCapitalL]\), \(\[Beta]\)]\)\[Alpha]"},
    (* non-scalars *)
    {Lbetagamb[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*SubscriptBox[\(\[ScriptCapitalL]\), \(\[Beta]\)]\)\!\(\*OverscriptBox[\(\[Gamma]\), \(_\)]\)"},
    {LbetaexAb[-i, -j], Symmetric[{-i, -j}], PrintAs -> "\!\(\*SubscriptBox[\(\[ScriptCapitalL]\), \(\[Beta]\)]\)\!\(\*OverscriptBox[\(A\), \(_\)]\)"},
    {LbetaLt[i],                             PrintAs -> "\!\(\*SubscriptBox[\(\[ScriptCapitalL]\), \(\[Beta]\)]\)\!\(\*OverscriptBox[\(\[CapitalLambda]\), \(~\)]\)"},
    {LbetaB[i],                              PrintAs -> "\!\(\*SubscriptBox[\(\[ScriptCapitalL]\), \(\[Beta]\)]\)B"}
  ];

(* Matter *)

MatterVarlist =
  TempTensors[
    {rho[],                           PrintAs -> "\[Rho]"},
    {Sm[-i],                          PrintAs -> "S"},
    {Ss[-i, -j], Symmetric[{-i, -j}], PrintAs -> "S"},
    {trSs[],                          PrintAs -> "S"}
  ];

(* Constraints *)

ConstraintVarlist =
  GridTensors[
    {ZtC[i], PrintAs -> "\!\(\*OverscriptBox[\(Z\), \(~\)]\)"},
    {HC[],   PrintAs -> "H"},
    {MtC[i], PrintAs -> "\!\(\*OverscriptBox[\(M\), \(~\)]\)"}
  ];

(************)

(* Constant *)

(************)

DefConstantSymbol[cpi, PrintAs -> "\[Pi]"];

DefConstantSymbol[ckappa1, PrintAs -> "\!\(\*SubscriptBox[\(\[Kappa]\), \(1\)]\)"];

DefConstantSymbol[ckappa2, PrintAs -> "\!\(\*SubscriptBox[\(\[Kappa]\), \(2\)]\)"];

DefConstantSymbol[ckappa3, PrintAs -> "\!\(\*SubscriptBox[\(\[Kappa]\), \(3\)]\)"];

DefConstantSymbol[cmuL, PrintAs -> "\!\(\*SubscriptBox[\(\[Mu]\), \(L\)]\)"];

DefConstantSymbol[cmuS, PrintAs -> "\!\(\*SubscriptBox[\(\[Mu]\), \(S\)]\)"];

DefConstantSymbol[ceta, PrintAs -> "\[Eta]"];

