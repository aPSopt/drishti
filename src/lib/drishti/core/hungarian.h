/*! -*-c++-*-
  @file   hungarian.h
  @brief  Adaptation of hungarian assignment algorithm.

  \copyright Copyright 2017 Elucideye, Inc. All rights reserved (modifications)
  
  \license{This file is released under the Apache License, Version 2.0}

  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  Copyright 2010-2014 Google
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
  
     http:www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  IMPORTANT NOTE: we advise using the code in
  graph/linear_assignment.h whose complexity is
  usually much smaller.
  TODO(user): base this code on LinearSumAssignment.

  An O(n^4) implementation of the Kuhn-Munkres algorithm (a.k.a. the
  Hungarian algorithm) for solving the assignment problem.
  The assignment problem takes a set of agents, a set of tasks and a
  cost associated with assigning each agent to each task and produces
  an optimal (i.e., least cost) assignment of agents to tasks.
  The code also enables computing a maximum assignment by changing the
  input matrix.

  This code is based on (read: translated from) the Java version
  (read: translated from) the Python version at
    http:www.clapper.org/software/python/munkres/
  which in turn is based on
    http://www.public.iastate.edu/~ddoty/HungarianAlgorithm.html.

*/

#include "drishti/core/drishti_core.h" // namespace definition

#include <opencv2/core/core.hpp>

#include <iostream>

#ifndef __drishti_core_hungarian_h__
#define __drishti_core_hungarian_h__


#include <unordered_map>
#include <vector>

DRISHTI_CORE_NAMESPACE_BEGIN

// See IMPORTANT NOTE at the top of the file.
void MinimizeLinearAssignment(const std::vector<std::vector<double>>& cost,
    std::unordered_map<int, int>& direct_assignment,
    std::unordered_map<int, int>& reverse_assignment);

// See IMPORTANT NOTE at the top of the file.
void MaximizeLinearAssignment(const std::vector<std::vector<double>>& cost,
    std::unordered_map<int, int>& direct_assignment,
    std::unordered_map<int, int>& reverse_assignment);

DRISHTI_CORE_NAMESPACE_END

#endif // __drishti_core_hungarian_h__
