# BioFast
Face verification security


## hashExperimentCode
The folder contains the face verification experiment for face datasets LFW, AgeDB and CFP-FP.
We use face model ArcFace to extract feature vector from face datasets. We use different γ and p in our experiment setting
and get the face verification results.

## homorphic_experiment
The folder contains the code for homomorphic encryption. The packing technique for the inner product of multiple feature vectors is contained in the folder.

## hash_comm
The folder contains the code for hash threshold comparison. We do experiment by different p and lead to different number hashes.


##
Note that, to run our code, need to download the Seal and ABY First.


The files in folder hashExperimentCode use python code, they can run in jupyter notebook or pycharm.

The files in folders homorphic_experiment and hash_comm use C++ code, they run by C++ project way.
cd to the   /build
and then run

cmake ..

make