#include "./depend.h"
#include <Eigen/Core>
#include <Eigen/SparseLU>
#include <glog/logging.h>

int main() {
    google::InitGoogleLogging("process_log");
    FLAGS_log_dir = "./log/";
    FLAGS_alsologtostderr = true; // 设置日志消息除了日志文件之外是否去标准输出

    return 0;
}
