


"abc", "bca", "cba", "xyzd", "zyxd"
put(sorted(word), word)

"abc": ["abc", "bca"]


bucketArray = [list, list, list, list]


put(key, value)

key string : value array or linkeslist

chaining

buckets = [list, list, list, ...]
/*
bucket idx: Node (key 0, abc) --> LinkedList (key 1, dxyz) --> LinkedList (key 2, aab) --> LinkeList(key 3, def) ....
              |                          |
            Node->data (abc, abc)            Node (dxyz, xyzd)
              |
            Node->data (abc, bca)
*/


