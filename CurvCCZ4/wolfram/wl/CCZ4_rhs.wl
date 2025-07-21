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

SetEQN[trLt[i_], eOSvt[i, -k] trLtO[k]];

SetEQN[beta[i_], eOSvt[i, -k] betaO[k]];

SetEQN[B[i_], eOSvt[i, -k] BO[k]];

SetEQN[deps[k_, i_, j_], eOSco[i, m] eOSco[j, n] depsO[k, -m, -n] + deOSco[k, i, m] eOSco[j, n] epsO[-m, -n] + eOSco[i, m] deOSco[k, j, n] epsO[-m, -n]];

SetEQN[dgamb[k_, i_, j_], dgamh[k, i, j] + deps[k, i, j]];

SetEQN[dexAb[k_, i_, j_], eOSco[i, m] eOSco[j, n] dexAbO[k, -m, -n] + deOSco[k, i, m] eOSco[j, n] exAbO[-m, -n] + eOSco[i, m] deOSco[k, j, n] exAbO[-m, -n]];

SetEQN[dtrLt[k_, i_], eOSvt[i, -m] dtrLtO[k, m] + deOSvt[k, i, -m] trLtO[m]];

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

(*******)

(* EOM *)

(*******)
