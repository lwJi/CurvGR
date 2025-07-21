(* ::Package:: *)

(* CCZ4_rhs.wl *)

(* (c) Liwei Ji, 07/2025 *)

(* See arXiv:2002.06225 [gr-qc] *)

(****************)

(* Intermediate *)

(****************)

SetEQN[eps[i_, j_], eOSco[i, k] eOSco[j, l] epsO[-k, -l]];

SetEQN[gamb[i_, j_], gamh[i, j] + eps[i, j]];

SetEQN[exAb[i_, j_], eOSco[i, k] eOSco[j, l] exAbO[-k, -l]];

SetEQN[Lt[i_], eOSvt[i, -k] LtO[k]];

SetEQN[beta[i_], eOSvt[i, -k] betaO[k]];

SetEQN[B[i_], eOSvt[i, -k] BO[k]];

SetEQN[deps[k_, i_, j_], eOSco[i, m] eOSco[j, n] depsO[k, -m, -n] + deOSco[k, i, m] eOSco[j, n] epsO[-m, -n] + eOSco[i, m] deOSco[k, j, n] epsO[-m, -n]];

SetEQN[dgamb[k_, i_, j_], dgamh[k, i, j] + deps[k, i, j]];

SetEQN[dexAb[k_, i_, j_], eOSco[i, m] eOSco[j, n] dexAbO[k, -m, -n] + deOSco[k, i, m] eOSco[j, n] exAbO[-m, -n] + eOSco[i, m] deOSco[k, j, n] exAbO[-m, -n]];

SetEQN[dLt[k_, i_], eOSvt[i, -m] dLtO[k, m] + deOSvt[k, i, -m] LtO[m]];

SetEQN[dbeta[k_, i_], eOSvt[i, -m] dbetaO[k, m] + deOSvt[k, i, -m] betaO[m]];

SetEQN[dB[k_, i_], eOSvt[i, -m] dBO[k, m] + deOSvt[k, i, -m] BO[m]];

SetEQN[ddeps[k_, l_, i_, j_], eOSco[i, m] eOSco[j, n] ddepsO[k, l, -m, -n] + deeOSco[k, i, m, j, n] depsO[l, -m, -n] + deeOSco[l, i, m, j, n] depsO[k, -m, -n] + ddeeOSco[k, l, i, m, j, n] epsO[-m, -n]];

SetEQN[ddbeta[k_, l_, i_], eOSvt[i, -j] ddbetaO[k, l, j] + deOSvt[k, i, -j] dbetaO[l, j] + deOSvt[l, i, -j] dbetaO[k, j] + ddeOSvt[k, l, i, -j] betaO[j]];

SetEQN[psim4[], Exp[-4 phi[]]];

SetEQN[psi4[], 1 / psim4[]];

SetEQN[dgam[k_, i_, j_], psi4[] (4 dphi[k] gamb[i, j] + dgamb[k, i, j])];

SetEQN[invgam[i_, j_], psim4[] invgamb[i, j]];

SetEQN[gam[i_, j_], psi4[] gamb[i, j]];

SetEQN[GambDDD[k_, i_, j_], 1/2 (dgamb[i, j, k] + dgamb[j, k, i] - dgamb[k, i, j])];

SetEQN[Gamb[k_, i_, j_], invgamb[k, l] GambDDD[-l, i, j]];

SetEQN[GamDDD[k_, i_, j_], 1/2 (dgam[i, j, k] + dgam[j, k, i] - dgam[k, i, j])];

SetEQN[Gam[k_, i_, j_], invgam[k, l] GamDDD[-l, i, j]];

SetEQN[trbDbeta[], dbeta[-k, k] + beta[k] dgamhdet[-k] / (2 gamhdet[])];

SetEQN[bDbDphi[i_, j_], ddphi[i, j] - Gamb[k, i, j] dphi[-k]];

SetEQN[bDbDalpha[i_, j_], ddalpha[i, j] - Gamb[k, i, j] dalpha[-k]];

SetEQN[hDgamb[k_, i_, j_], deps[k, i, j] - Gamh[m, k, i] eps[j, -m] - Gamh[m, k, j] eps[i, -m]];

SetEQN[hDLt[k_, i_], dLt[k, i] + Gamh[i, k, -m] Lt[m]];

SetEQN[hDbeta[k_, i_], dbeta[k, i] + Gamh[i, k, -m] beta[m]];

SetEQN[dhDgamb[k_, l_, i_, j_], ddeps[k, l, i, j] - (dGamh[k, m, l, i] eps[j, -m] + dGamh[k, m, l, j] eps[i, -m]) - (Gamh[m, l, i] deps[k, j, -m] + Gamh[m, l, j] deps[k, i, -m])];

SetEQN[hDhDgamb[k_, l_, i_, j_], dhDgamb[k, l, i, j] - Gamh[m, k, l] hDgamb[-m, i, j] - Gamh[m, k, i] hDgamb[l, -m, j] - Gamh[m, k, j] hDgamb[l, i, -m]];

SetEQN[hDhDbeta[i_, j_, k_], ddbeta[i, j, k] + dGamh[i, k, j, -m] beta[m] + (Gamh[k, -l, i] dbeta[j, l] + Gamh[k, -l, j] dbeta[i, l]) - Gamh[l, i, j] dbeta[-l, k] + (Gamh[k, i, -l] Gamh[l, j, -m] - Gamh[l, i, j] Gamh[k, -l, -m]) beta[m]];

SetEQN[trexAb[], gamb[k, l] exAb[-k, -l]];

SetEQN[trbDbDphi[], gamb[k, l] bDbDphi[-k, -l]];

SetEQN[trbDphibDphi[], gamb[k, l] dphi[-k] dphi[-l]];

SetEQN[trbDbDalpha[], gamb[k, l] bDbDalpha[-k, -l]];

SetEQN[DGamDDD[k_, i_, j_], (hDgamb[i, j, k] + hDgamb[j, k, i] - hDgamb[k, i, j])];

SetEQN[DGam[k_, i_, j_], gamb[k, l] DGamDDD[-l, i, j]];

SetEQN[trDGam[k_], gamb[i, j] DGam[k, -i, -j]];

SetEQN[ZU[i_], 1/2 psim4[] (Lt[i] - trDGam[i])];

SetEQN[ZD[i_], gam[i, -j] ZU[j]];

SetEQN[RZ[i_, j_], -4 (ZD[i] dphi[j] + ZD[j] dphi[i]) + (gam[-k, i] (Gam[k, j, -l] - Gamh[k, j, -l]) + gam[-k, j] (Gam[k, i, -l] - Gamh[k, i, -l])) ZU[l]];

SetEQN[Rb[i_, j_], -(1/2) invgamb[k, l] hDhDgamb[-k, -l, i, j] + 1/2 (gamb[-k, i] hDLt[j, k] + gamb[-k, j] hDLt[i, k]) + 1/2 trDGam[k] (DGam[i, j, -k] + DGam[j, i, -k]) + invgamb[k, l] (1/2 (DGam[m, -k, i] DGam[j, -m, -l] + DGam[m, -k, j] DGam[i, -m, -l]) + DGam[m, i, -k] DGam[-m, j, -l]) + RZ[i, j]];

SetEQN[trRb[], invgamb[k, l] Rb[-k, -l]];

SetEQN[RbTF[i_, j_], Rb[i, j] - 1/3 gamb[i, j] trRb[]];

SetEQN[Rphi[i_, j_], -2 alpha[] bDbDphi[i, j] + 4 alpha[] dphi[i] dphi[j] + 2 (dalpha[i] dphi[j] + dalpha[j] dphi[i])];

SetEQN[RphiTF[i_, j_], Rphi[i, j] - 1/3 gamb[i, j] invgamb[k, l] Rphi[-k, -l]];

SetEQN[Ralpha[i_, j_], -bDbDalpha[i, j]];

SetEQN[RalphaTF[i_, j_], Ralpha[i, j] - 1/3 gamb[i, j] invgamb[k, l] Ralpha[-k, -l]];

SetEQN[Lbetaphi[], beta[k] dphi[-k]];

SetEQN[Lbetagamb[i_, j_], beta[k] dgamb[-k, i, j] + (gamb[i, -k] dbeta[j, k] + gamb[j, -k] dbeta[i, k])];

SetEQN[LbetatrK[], beta[k] dtrK[-k]];

SetEQN[LbetaexAb[i_, j_], beta[k] dexAb[-k, i, j] + (exAb[i, -k] dbeta[j, k] + exAb[j, -k] dbeta[i, k])];

SetEQN[LbetaLt[i_], beta[k] dLt[-k, i] - Lt[k] dbeta[-k, i]];

SetEQN[LbetaTheta[], beta[k] dTheta[-k]];

SetEQN[Lbetaalpha[], beta[k] dalpha[-k]];

SetEQN[LbetaB[i_], beta[k] dB[-k, i] + B[k] dbeta[-k, i]];

(*******)

(* EOM *)

(*******)
