/*****************************************************************************
 *                                                                           *
 *             Mixed-mode OpenMP/MPI MicroBenchmark Suite - Version 1.0      *
 *                                                                           *
 *                            produced by                                    *
 *                                                                           *
 *                Mark Bull, Jim Enright and Fiona Reid                      *
 *                                                                           *
 *                                at                                         *
 *                                                                           *
 *                Edinburgh Parallel Computing Centre                        *
 *                                                                           *
 *   email: markb@epcc.ed.ac.uk, fiona@epcc.ed.ac.uk                         *
 *                                                                           *
 *                                                                           *
 *              Copyright 2012, The University of Edinburgh                  *
 *                                                                           *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *      http://www.apache.org/licenses/LICENSE-2.0                           *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/

#ifndef PT_TO_PT_MULTIPINGPING_H_
#define PT_TO_PT_MULTIPINGPING_H_

#include "benchmarkSetup.h"
#include "output.h"
#include "parallelEnvironment.h"

#include <stdio.h>

/* function prototypes */
int multiPingping(int benchmarkType);
int allocateMultiPingpingData(int sizeofBuffer);
int freeMultiPingpingData();
int masteronlyMultiPingping(int totalReps, int dataSize);
int funnelledMultiPingping(int totalReps, int dataSize);
int multipleMultiPingping(int totalReps, int dataSize);
int testMultiPingping(int sizeofBuffer, int dataSize);

/* variable declaration */
int pingNodeA, pingNodeB;
int otherPingRank;
int sizeofBuffer;
int *pingSendBuf, *pingRecvBuf;
int *finalRecvBuf;
int *testBuf;

#endif /* PT_TO_PT_MULTIPINGPING_H_ */
