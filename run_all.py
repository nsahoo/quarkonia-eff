#!/usr/bin/python

import sys
import subprocess

files = ['./inputs/rootuple-Onia2MuMu_JPsiMM-PGun-PtFlat-NF.root',
         './inputs/rootuple-Onia2MuMu_Psi2SMM-PGun-PtFlat-NF.root',
         './inputs/rootuple-Onia2MuMu_Ups1SMM-PGun-PtFlat-NF.root',
         './inputs/rootuple-Onia2MuMu_Ups2SMM-PGun-PtFlat-NF.root',
         './inputs/rootuple-Onia2MuMu_Ups3SMM-PGun-PtFlat-NF.root']

mesons = ['JPsi', 'Psi2S', 'Ups1S', 'Ups2S', 'Ups3S']

if len(files) != len(mesons):
    print 'wrong number of elements'
    exit()

if len(sys.argv) == 2:
    command = './' + sys.argv[1]
else:
    command = './eff'

for i in range(len(files)):
    options_1 = ["--tail", mesons[i], "--file", files[i], "--meson", mesons[i]]
    options_2 = ["--tail", mesons[i] + "_barrel", "--file", files[i], "--meson", mesons[i], "--barrel"]
    #if command is './eff':
    #    trig = 2
    #else:
    #    trig = 1
    trig = 2
    for j in range(trig):
        if j == 1:
            options_i = options_1
        else:
            options_i = options_2
#["--tail", mesons[i] + "_barrel", "--file", files[i], "--meson", mesons[i], "--barrel"]
        full_command = [command] + options_i
        print full_command
        subprocess.call(full_command)
