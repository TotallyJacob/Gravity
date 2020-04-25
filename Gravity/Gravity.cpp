#include "Gravity.h"

Gravity::Gravity() : Renderer("Gravity", 1280, 720){

}

//Main
void Gravity::init() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//test

#define TIMES 1
#define TEST_TIMES 1

	double timeTaken[TEST_TIMES];

	bool test1 = true, test2 = true;

	if (test1) {
		double time = glfwGetTime();
		for (int test = 0; test < TEST_TIMES; test++) {
			
			for (int i = 0; i < TIMES; i++);
		
			
			timeTaken[test] = glfwGetTime() - time;
		}

		double advTime = 0;

		for (int i = 0; i < TEST_TIMES; i++)
			advTime += timeTaken[i];

		advTime = advTime / float(TEST_TIMES);

		std::cout << "Json Read 1: " << advTime << std::endl;
	}
	
}

int getNumVertsForDraw(unsigned int points) {
	return (2 * points) * (3 * 2);
}
int getNumVertsForData(unsigned int points) {
	return 4 * points * 3;
}
//Gens points for glDrawArrays
void genPoint(glm::vec3 *points, float thickness, glm::vec3 offset) {
		points[0] = glm::vec3(0, 0, 0) + offset;
		points[1] = glm::vec3(0, -thickness, 0) + offset;
		points[3] = glm::vec3(thickness, -thickness, 0) + offset;
		points[4] = glm::vec3(thickness, 0, 0) + offset;
}
void genGrid(float *arr, unsigned int *index,unsigned int num_points_y, unsigned int num_points_x, float thickness, float distance) {
	glm::vec3 offset_y = glm::vec3(0.f, 0.f, 0.f);
	glm::vec3 offset_x = glm::vec3(0.f, 0.f, 0.f);


	//Adds point data to arr
	for (int point_x = 0; point_x < num_points_x; point_x++) {
		offset_x = glm::vec3(num_points_x * distance, 0, 0);

		for (int point_y = 0; point_y < num_points_y; point_y++) {
			offset_y = glm::vec3(0, num_points_y * distance, 0);

			glm::vec3 points[4];
			genPoint(points, thickness, offset_y + offset_x);

			unsigned int offset = (4 * 3 * point_y) +(4*3*num_points_y*point_x);

			for (int i = 0; i < 4; i++) {
				arr[(3 * i) + offset + 0] = points[i].x;
				arr[(3 * i) + offset + 1] = points[i].y;
				arr[(3 * i) + offset + 2] = points[i].z;
			}

		}
	}

	//Adds index data to index
	unsigned int n_total = num_points_y-1;
	unsigned int points = num_points_y + num_points_x;
	//Adding the main squares
	for (int x = 0; x < num_points_x; x++) {
		for (int y = 0; y < num_points_y; y++) {
			unsigned int start_offset = (y * 4) + (x * (num_points_y * 4));
			unsigned int array_offset = ((y*6*2)) + (x * (num_points_y * 6 * 2));

			//Point
			index[array_offset + 0] = 0 + start_offset;
			index[array_offset + 1] = 1 + start_offset;
			index[array_offset + 2] = 2 + start_offset;

			index[array_offset + 3] = 2 + start_offset;
			index[array_offset + 4] = 3 + start_offset;
			index[array_offset + 5] = 0 + start_offset;
			//Connecting
			if (y == 0) {
				index[array_offset + 6] = 1 + start_offset;
				index[array_offset + 7] = 4 + start_offset;
				index[array_offset + 8] = 7 + start_offset;

				index[array_offset + 9] = 7 + start_offset;
				index[array_offset + 10] = 2 + start_offset;
				index[array_offset + 11] = 1 + start_offset;
			}

			if (y > 0 && x == 0) {
				index[array_offset + 6] = 3 + start_offset;
				index[array_offset + 7] = 2 + start_offset;
				index[array_offset + 8] = (2+4+1) + start_offset;

				index[array_offset + 9] = (2+4+1) + start_offset;
				index[array_offset + 10] = (2+4+0) + start_offset;
				index[array_offset + 11] = (3) + start_offset;
			}
			if (x > 0 && y > 0) {
				index[array_offset + 6] = 0 + start_offset;
				index[array_offset + 7] = 0-8+3 + start_offset;
				index[array_offset + 8] = 0-8+2 + start_offset;

				index[array_offset + 9] = (0-8+2) + start_offset;
				index[array_offset + 10] = (1) + start_offset;
				index[array_offset + 11] = (0) + start_offset;
			}
			
		}
	}
}

void Gravity::loop() {

/*#define Y 2
#define X 2

	unsigned int num_data = getNumVertsForData(X + Y);
	unsigned int num_index = getNumVertsForDraw(X + Y);

	float *arr = new float[num_data];
	unsigned int *index = new unsigned int[num_index];

	genGrid(arr, index, Y, X, 0.2f, 0.4f);

	for (int i = 0; i < num_index; i++)
		std::cout << index[i] << std::endl;

	//TEST
	ShaderProgram test({
		"test.vert.shader",
		//"test.tess_control.shader",
		//"test.tess_evaluation.shader",
		//"test.geo.shader",
		"test.frag.shader" 
	});


	unsigned int vao = 0, vbo = 0, ibo = 0;
	//Creation
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	//bindings
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	//Attaching data
	glBufferData(GL_ARRAY_BUFFER, num_data * sizeof(float), &arr[0], GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_index * sizeof(unsigned int), &index[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 3, (const void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete[] arr;
	delete[] index;
	(
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.1f, -1.f));
	//
	*/

	Camera camera;
	camera.setLocation(glm::vec3(0, 0, 2.f));

	perspectiveMatrix = glm::perspective(45.f, 16.f/9.f, 0.1f, 100.f);

	SolarSystem solarSystem("testy");

	double tick_time = 0;
	double tick_time_slow = 0;

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	PlanetManager manager;

	while (!glfwWindowShouldClose(window)) {
		double startTime = glfwGetTime();

		glClearColor(0.f, 0.f, 0.f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		camera.updateViewMatrix();

		//Drawing
		solarSystem.draw(camera, &perspectiveMatrix[0][0]);

		/*glUseProgram(test);

		glBindVertexArray(vao);

		ShaderProgram::sendModelMatrix(test, &model[0][0]);
		ShaderProgram::sendPerspectiveMatrix(test, &perspectiveMatrix[0][0]);
		ShaderProgram::sendViewMatrix(test, &camera.getViewMatrix()[0][0]);
		
		glUniform4f(glGetUniformLocation(test, "color"), 1.0f, 1.0f, 1.0f, 1.0f);

		glDrawElements(GL_TRIANGLES, num_index, GL_UNSIGNED_INT, nullptr);

		glUseProgram(0);
		*/

		glfwSwapBuffers(window);
		glfwPollEvents();

		tick_time += glfwGetTime() - startTime;

		if (tick_time >= TICK_RATE) {
			tick_time = 0;
			tick();
		}

		if (tick_time_slow >= TICK_RATE_SLOW) {
			tick_time_slow = 0;
			tick_slow();
			//Other
			manager.updateActivePlanets();
			manager.updateData(camera.getLocation());
		}
	}
}

void Gravity::cleanUp() {
	glfwTerminate();
}

//Updates
void Gravity::tick() {
	int width = 0, height = 0;
	glfwGetWindowSize(window, &width, &height);
	if (width != windowData.width || height != windowData.height) {

		windowData.width = width;
		windowData.height = height;

		resize(perspectiveMatrix);
	}
}
void Gravity::tick_slow() {

}

void Gravity::resize(glm::mat4 &perspectiveMatrix) {
	glViewport(0, 0, windowData.width, windowData.height);
	perspectiveMatrix = glm::perspective(45.f, float(windowData.width)/float(windowData.height), 0.1f, 100.f);
}