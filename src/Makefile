# ======================
# Create ROS2 C++ package
# ======================
pkg-cpp:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
		echo "Usage: make pkg-cpp <package_name>"; \
		exit 1; \
	fi
	ros2 pkg create --build-type ament_cmake $(word 2,$(MAKECMDGOALS))

# ======================
# Create ROS2 Python package
# ======================
pkg-py:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
		echo "Usage: make pkg-py <package_name>"; \
		exit 1; \
	fi
	ros2 pkg create --build-type ament_python $(word 2,$(MAKECMDGOALS))

# ======================
# Ignore extra args
# ======================
%:
	@:
