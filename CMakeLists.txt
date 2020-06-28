PROJECT(epcc)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(OpenMP REQUIRED)
find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})

SET(SOURCES
    src/mixedModeBenchmarkDriver.c
    src/benchmarkSetup.h
    src/benchmarkSetup.c
    src/parallelEnvironment.h
    src/parallelEnvironment.c
    src/output.h
    src/output.c
    src/pt_to_pt_pingpong.h
    src/pt_to_pt_pingpong.c
    src/pt_to_pt_pingping.h
    src/pt_to_pt_pingping.c
    src/pt_to_pt_multiPingpong.h
    src/pt_to_pt_multiPingpong.c
    src/pt_to_pt_multiPingping.h
    src/pt_to_pt_multiPingping.c
    src/pt_to_pt_haloexchange.h
    src/pt_to_pt_haloexchange.c
    src/collective_barrier.h
    src/collective_barrier.c
    src/collective_broadcast.h
    src/collective_broadcast.c
    src/collective_scatterGather.h
    src/collective_scatterGather.c
    src/collective_reduction.h
    src/collective_reduction.c
    src/collective_alltoall.h
    src/collective_alltoall.c
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