
#!/bin/bash

problem_name=$1
ext_name=$2
file=$3
base_url=${problem_name%_*}
url=https://atcoder.jp/contests/${base_url}/tasks/${problem_name//-/_}

# submit
oj submit --yes ${url} ${file}