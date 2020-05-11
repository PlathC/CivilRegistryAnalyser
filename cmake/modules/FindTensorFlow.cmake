
if(WIN32)

    message("Looking for environment variable TENSORFLOW_LIBRARY which should point on <YourPathToTensorflowBuild>/bazel-bin/tensorflow/tensorflow.lib")
    set(TensorFlow_LIBRARY $ENV{TENSORFLOW_LIBRARY}/tensorflow/tensorflow.lib)
    if(TensorFlow_LIBRARY)
        message("Found Tensorflow library !")
        message("Looking for environment variable TENSORFLOW_INCLUDES_DIR which should point on <YourPathToTensorflowBuild>/bazel-tensorflow")

        list(APPEND TensorFlow_INCLUDE_DIR $ENV{TENSORFLOW_INCLUDES_DIR})
        if(TensorFlow_INCLUDE_DIR)
            message("Found Tensorflow include dir, looking for headers paths.")
            list(APPEND TensorFlow_INCLUDE_DIR $ENV{TENSORFLOW_INCLUDES_DIR}\\external\\com_google_absl)
            list(APPEND TensorFlow_INCLUDE_DIR $ENV{TENSORFLOW_INCLUDES_DIR}\\external\\eigen_archive)
            list(APPEND TensorFlow_INCLUDE_DIR $ENV{TENSORFLOW_INCLUDES_DIR}\\external\\com_google_protobuf\\src)
            list(APPEND TensorFlow_INCLUDE_DIR $ENV{TENSORFLOW_LIBRARY})
            set(TensorFlow_FOUND TRUE)
        else()
            message("Can't find TensorFlow_INCLUDE_DIR environment variable.")
        endif()
    else()
        message("Can't find TENSORFLOW_LIBRARY environment variable which is needed.")
    endif()
else()
    message("This loader does not currently support other platforms than Windows.")
endif()

set(TensorFlow_INCLUDE_DIR "${TensorFlow_INCLUDE_DIR}" CACHE PATH "The path to tensorflow header files")
set(TensorFlow_LIBRARY "${TensorFlow_LIBRARY}" CACHE FILEPATH "The C++ library of TensorFlow")
set(TensorFlow_FOUND "${TensorFlow_FOUND}" CACHE BOOL "A flag stating if TensorFlow has been found")