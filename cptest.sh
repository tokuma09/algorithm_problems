
#!/bin/bash

problem_name=$1
ext_name=$2
file=$3
test_dir=samples/${problem_name}
base_url=${problem_name%_*}
url=https://atcoder.jp/contests/${base_url}/tasks/${problem_name//-/_}


# make sample directory
if [ ! -e ${test_dir} ]; then
    oj dl -d ${test_dir} ${url}
fi

# test
case ${ext_name} in
    ".py")
        oj test -c "python3 ${file}" -d ${test_dir}
    ;;
    ".jl")
        oj test -c "julia ${file}" -d ${test_dir}
    ;;
    ".cpp")
        g++ -std=c++14 ${file} && oj test -c "./a.out" -d ${test_dir}
    ;;
esac
