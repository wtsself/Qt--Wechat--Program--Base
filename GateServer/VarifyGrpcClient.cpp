#include "VarifyGrpcClient.h"
#include"ConfigMgr.h"
VerifyGrpcClient::VerifyGrpcClient() {
	auto& gCfmgr = ConfigMgr::Inst();
	std::string host = gCfmgr["VarifyServer"]["Host"];
	std::string port = gCfmgr["VarifyServer"]["Port"];
	pool_.reset(new RPConPool(5, host, port));

}