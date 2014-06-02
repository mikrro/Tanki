#include "PoolingAcceptor.h"
#include "ProtobufConnection.h"
#include "IoHarbour.h"
#include "ConnectionPool.h"
#include "ConnectionBridge.h"
#include "ProtobufConnectionFactory.h"
#include "GameEngine.h"
#include "MessageHandler.h"

#include "message.pb.h"
#include "glog/logging.h"

#include <thread>

using namespace ships;

int main(int argc, char * argv[]) {
	google::InitGoogleLogging(argv[0]);
	google::SetLogDestination(google::INFO, "server.log");

	// Setup IoHarbour
	auto harbour = std::make_shared<IoHarbour>();

	// Setup PoolingAcceptor
		//	Setup MessageHandler
	auto msgHandler = std::make_shared<MessageHandler<MessageType, DataMsg>>();
	msgHandler->setTypeMethod([](const DataMsg& msg) -> MessageType {

		return msg.type();
	});

	//	Setup ConnectionFactory
	auto connectionFactory = std::make_shared<ProtobufConnectionFactory>(harbour);
	connectionFactory->setMsgHandler(msgHandler);

	auto connectionPool = std::make_shared<ConnectionPool>();
	connectionPool->setConnsToSignal(2);
	auto acceptor = std::make_shared<PoolingAcceptor>(harbour, connectionPool, connectionFactory);

	//	Setup GameEngine and connect it to server
	auto gameEngine = std::make_shared<GameEngine>();
	auto bridge = std::make_shared<ConnectionBridge>(connectionPool, gameEngine);
	connectionPool->registerConnectionObserver(bridge);



	//	Run
	acceptor->listen("127.0.0.1", atoi(argv[1]));
	std::thread thread([&]() { harbour->run();});

	std::shared_ptr<ProtobufConnection> connection1 = std::make_shared<ProtobufConnection>(harbour);
	std::shared_ptr<ProtobufConnection> connection2 = std::make_shared<ProtobufConnection>(harbour);

//	std::this_thread::sleep_for(std::chrono::milliseconds(300));
//	connection1->connect("127.0.0.1", atoi(argv[1]));
//	connection2->connect("127.0.0.1", atoi(argv[1]));

	thread.join();
	return 0;
}
