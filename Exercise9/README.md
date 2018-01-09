# Exercise 9: OpenGL primer

## Assignment 1: OpenGL

a) Explain what an OpenGL context is, how you change it and what happens if you change it .

OpenGL context is essentially a state machine that stores all data related to the rendering of your application.
When your application closes, the OpenGL context is destroyed and everything is cleaned up.

b) Explain the following types of objects in OpenGL and what they are used for
- Vertex-buffer-object: it's just an array of data (usually floats). It is a memory buffer in the high speed memory of your video card designed to hold information about vertices.
- Element-buffer-object: are used as source of indices during rendering of indexed primitives.
- Vertex-array-object:  is an object which contains one or more Vertex Buffer Objects and is
designed to store the information for a complete rendered object.
- Shader object: shader variables: uniform variables and attribute variables. Attribute variables
can have a different value for each vertex. Uniform variables keep the same value for multiple
vertices.
- Texture: Textures are basically 2D images that you can apply to your 3D objects. Textures live in
video memory. That is, you upload the data for the texture to the graphics card before you can
use it.

c) Explain line-by-line the following shader code
- Vertex shader:
```
#version 330 core // means the version 3.3
layout (location = 0) in vec3 position; // is the location of the input variable
out vec4 vertexColor; // is the output of the vertex
void main() {
	gl_Position = vec4(position, 1.0); // is the resulting screen position; it's a built-in output variable
	vertexColor = vec4(0.5f, 0.0f, 0.0f, 1.0f); // vec4 takes out x, y, z coordinates, and the last one is w is for homogeneous coordinates (for transformation matrices).
}
```

- Fragment shader:
```
#version 330 core // means the version is 3.3
in vec4 vertexColor; // is the atribute (input) of the vertex
out vec4 color; // is the output of the vertex
void main() {
	color = vertexColor; // we are assigning the value of the attribute to the output
}
```

d) Explain line-by-line the following code:
```
// we specify a total of 3 vertices (x,y,z) to render a triangle.
	float vertices[] = {
	0.0f,  0.5f,  0.0f,
	0.5f, -0.5f,  0.0f,
	-0.5f, -0.5f,  0.0f
};
```

We now have the vertices of our triangle, then
```
GLuint vbo = 0; // create and initialize vertex-buffer-object to 0
glGenBuffers(1, &vbo); // allocate and assign vbo to our handle
glBindBuffer(GL_ARRAY_BUFFER, vbo); // bind vbo as being the active buffer and storing vertex attributes (coordinates).
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Copy the vertex data from vertices to our buffer.
```

Next we have
```
GLuint vao = 0; // create and initialize vertex-array-object to 0
glGenVertexArrays(1, &vao); // allocate and assign vo to our handle
glBindVertexArray(vao); // bind vao as the current used object
glEnableVertexAttribArray(0); // enable attribute index 0 as being used 
glBindBuffer(GL_ARRAY_BUFFER, vbo); // Bind vbo as being the active buffer and storing vertex attributes
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); // Specify that our coordinate data is going into attribute index 0, and contains three floats per vertex and null pointer
```

## Assignment 2: Graphics Pipelines

a) Explain the graphics pipeline of OpenGL (see the figure middle column). 

The graphics pipeline (rendering pipeline) is the sequence of steps that OpenGL takes when rendering objects.
1. Prepare vertex array data, and then render it
2. Vertex Processing:
	a. Each vertex is acted upon by a Vertex Shader. Each vertex in the stream is processed in turn into an output vertex.
	b. Optional primitive tessellation stages.
	c. Optional Geometry Shader primitive processing. The output is a sequence of primitives.
3. Vertex Post-Processing, the outputs of the last stage are adjusted or shipped to different
locations.
	a. Transform Feedback happens here.
	b. Primitive Clipping, the perspective divide, and the viewport transform to window space.
4. Primitive Assembly
5. Scan conversion and primitive parameter interpolation, which generates a number of
Fragments.
6. A Fragment Shader processes each fragment. Each fragment generates a number of outputs.
7. Per-Sample_Processing:
	a. Scissor Test
	b. Stencil Test
	c. Depth Test
	d. Blending
	e. Logical Operation
	f. Write Mask

b) Explain in detail how to pass data to a shader program.

Data is passed into compute shaders via uniform variables, buffer variables, textures or images. Uniform buffers and shader storage buffers are attached to binding points using glBindBufferBase() or glBindBufferRange() with a target of GL_UNIFORM_BUFFER or GL_SHADER_STORAGE_BUFFER respectively.
But for a vertex array where the number of components is 1, 2 or 4 and the data is packed, another option is to attach the buffer to a buffer texture with glTextureBuffer(), bind the texture to an image unit with glBindImageTexture(), and access the data in the compute shader using imageLoad().
Either way, one thing which you can do with vertex arrays but can't do using UBOs, storage buffers or images is decouple the actual data format from the shader. For a vertex shader which has an input variable (attribute) of type vec4, the actual attribute data in the buffer can have any type, any number of components; and any stride between the elements; and the data will appear as a sequence of vec4s to the shader. But for UBOs, storage buffers and images, the data format must match the interface block declaration or the format qualifier (for images).

c) Explain what type of shaders are necessary for modern OpenGL to render something on the screen.

- A vertex shader acts on vertices and is supposed to output the vertex position (→ gl_Position) on the viewport (i.e. screen).
- A fragment shader acts at the fragment level and is supposed to output the color (→ gl_FragColor) of the fragment.