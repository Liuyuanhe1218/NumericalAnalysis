

cc_library(
    name = "depend",
    srcs = ["depend.cpp"],
    hdrs = ["depend.h"],

	deps = [
		"@boost//:algorithm",
		"@boost//:asio_ssl",
		"@boost//:beast",
		"@boost//:thread",
		"@boost//:property_tree",
		"@com_github_google_glog//:glog",
		"@com_gitlab_libeigen_eigen//:eigen"
    ],
)

cc_library(
    name = "network",
    srcs = ["network.cpp"],
    hdrs = ["network.h"],

	deps = [
		":depend",
		"@boost//:asio_ssl",
		"@boost//:beast",
		"@boost//:thread",
		"@boost//:property_tree",
    ],
)


cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    includes = [],
    deps = [
		":depend",
		":network",
		"@com_github_google_glog//:glog",
    ],
)