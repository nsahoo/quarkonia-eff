#quarkonia

* Setup: You should have a g++ compiler and root in your enviroment.
The easiest way is setting up a cmssw enviroment.

```
export SCRAM_ARCH=slc6_amd64_gcc491
source /cvmfs/cms.cern.ch/cmsset_default.sh
cmsrel CMSSW_7_4_11_patch1
cd CMSSW_7_4_11_patch1/src/
cmsenv
git clone git@github.com:alberto-sanchez/quarkonia.git
cd quarkonia
make -j4
```

* Run: to run it you need to fill in inputs directory

```
cd inputs
ln -s <path-you-files>/rootuple-Onia2MuMu_*MM-PGun-PtFlat-NF.root .
cd ..
./run_all.py eff
./run_all.py acc
```

output should be in "plots" directory
