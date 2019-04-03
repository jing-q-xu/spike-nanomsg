///////////////////////////////////////////////////////////////////////////////
//bus

./bus node0 ipc:///tmp/node0.ipc ipc:///tmp/node1.ipc ipc:///tmp/node2.ipc & node0=$!
./bus node1 ipc:///tmp/node1.ipc ipc:///tmp/node2.ipc ipc:///tmp/node3.ipc & node1=$!
./bus node2 ipc:///tmp/node2.ipc ipc:///tmp/node3.ipc & node2=$!
./bus node3 ipc:///tmp/node3.ipc ipc:///tmp/node0.ipc & node3=$!
sleep 5
kill $node0 $node1 $node2 $node3

./bus node0 ipc:///tmp/node0.ipc ipc:///tmp/node1.ipc & node0=$!
./bus node1 ipc:///tmp/node1.ipc ipc:///tmp/node0.ipc ipc:///tmp/node2.ipc & node1=$!
./bus node2 ipc:///tmp/node2.ipc ipc:///tmp/node1.ipc & node2=$!
kill $node0 $node1 $node2 


./broker ipc:///tmp/node1.ipc ipc:///tmp/node2.ipc & broker=$!
./client node1 ipc:///tmp/node1.ipc ipc:///tmp/node2.ipc & node1=$!
./client node2 ipc:///tmp/node2.ipc ipc:///tmp/node1.ipc & node2=$!
kill $broker $node1 $node2 


./bus node1 ipc:///tmp/node1.ipc ipc:///tmp/node2.ipc & node1=$!
./bus node2 ipc:///tmp/node2.ipc ipc:///tmp/node1.ipc & node2=$!
kill $node1 $node2 