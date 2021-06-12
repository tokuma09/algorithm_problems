export $(cat .env | grep -v ^# | xargs)
oj login -u $ATCODER_USER -p $ATCODER_PASS "https://atcoder.jp/"