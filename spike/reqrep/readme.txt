./server 127.0.0.1:7070 & node0=$!
sleep(short time)
./client 127.0.0.1:7070 & node1=$!
sleep(long time)

kill $node1 $node2 