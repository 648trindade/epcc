PROJECT(epcc)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})

SET(SOURCES
    mixedModeBenchmarkDriver.c
    benchmarkSetup.h
    benchmarkSetup.c
    parallelEnvironment.h
    parallelEnvironment.c
    output.h
    output.c
    pt_to_pt_pingpong.h
    pt_to_pt_pingpong.c
    pt_to_pt_pingping.h
    pt_to_pt_pingping.c
    pt_to_pt_multiPingpong.h
    pt_to_pt_multiPingpong.c
    pt_to_pt_multiPingping.h
    pt_to_pt_multiPingping.c
    pt_to_pt_haloexchange.h
    pt_to_pt_haloexchange.c
    collective_barrier.h
    collective_barrier.c
    collective_broadcast.h
    collective_broadcast.c
    collective_scatterGather.h
    collective_scatterGather.c
    collective_reduction.h
    collective_reduction.c
    collective_alltoall.h
    collective_alltoall.c
)

add_executable(epcc ${SOURCES})
target_link_libraries(epcc PRIVATE ${MPI_LIBRARIES} OpenMP::OpenMP_C)

if(MPI_COMPILE_FLAGS)
  set_target_properties(epcc PROPERTIES
    COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
  set_target_properties(epcc PROPERTIES
    LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()