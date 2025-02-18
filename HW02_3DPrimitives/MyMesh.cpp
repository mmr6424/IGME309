#include "MyMesh.h"
void MyMesh::GenerateCube(float a_fSize, vector3 a_v3Color)
{
	if (a_fSize < 0.01f)
		a_fSize = 0.01f;

	Release();
	Init();

	float fValue = a_fSize * 0.5f;
	//3--2
	//|  |
	//0--1

	vector3 point0(-fValue, -fValue, fValue); //0
	vector3 point1(fValue, -fValue, fValue); //1
	vector3 point2(fValue, fValue, fValue); //2
	vector3 point3(-fValue, fValue, fValue); //3

	vector3 point4(-fValue, -fValue, -fValue); //4
	vector3 point5(fValue, -fValue, -fValue); //5
	vector3 point6(fValue, fValue, -fValue); //6
	vector3 point7(-fValue, fValue, -fValue); //7

	//F
	AddQuad(point0, point1, point3, point2);

	//B
	AddQuad(point5, point4, point6, point7);

	//L
	AddQuad(point4, point0, point7, point3);

	//R
	AddQuad(point1, point5, point2, point6);

	//U
	AddQuad(point3, point2, point7, point6);

	//D
	AddQuad(point4, point5, point0, point1);

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
//--- Completed ---//
void MyMesh::GenerateCone(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code
	//GenerateCube(a_fRadius * 2.0f, a_v3Color);
	std::vector<vector3> a_vPoints;
	float a_fPointIncrement = (2 * PI) / a_nSubdivisions;
	float a_fAngle = 0;
	for (int x = 0; x < a_nSubdivisions; x++)
	{
		float r = a_fRadius * cos(a_fAngle);
		float k = a_fRadius * sin(a_fAngle);
		// The division by 2 ensures that the axis of rotation is around the CENTER of the object, not around its bottom point
		a_vPoints.push_back(vector3(r, k, a_fHeight / 2));
		a_fAngle += a_fPointIncrement;
	}

	for (int i = 0; i < a_nSubdivisions; i++)
	{
		// The division by 2 ensures that the axis of rotation is around the CENTER of the object, not around its bottom point
		AddTri(vector3(0.0f, 0.0f, a_fHeight / 2),
			a_vPoints[i],
			a_vPoints[(i + 1) % a_nSubdivisions]);
		// The negative ensures that the height of the cone is correct, as the distance between height/2 and -height/2 is height
		AddTri(vector3(0.0f, 0.0f, -a_fHeight / 2),
			a_vPoints[(i + 1) % a_nSubdivisions],
			a_vPoints[i]);
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
//--- Completed ---//
void MyMesh::GenerateCylinder(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code
	//GenerateCube(a_fRadius * 2.0f, a_v3Color);
	std::vector<vector3> a_vBotPoints, a_vTopPoints;
	float a_fPointIncrement = (2 * PI) / a_nSubdivisions;
	float a_fAngle = 0;
	for (int x = 0; x < a_nSubdivisions; x++)
	{
		float r = a_fRadius * cos(a_fAngle);
		float k = a_fRadius * sin(a_fAngle);
		// The division by 2 ensures that the axis of rotation is around the CENTER of the object, not around its bottom point
		a_vBotPoints.push_back(vector3(r, k, -a_fHeight / 2));
		a_vTopPoints.push_back(vector3(r, k, a_fHeight / 2));
		a_fAngle += a_fPointIncrement;
	}

	for (int i = 0; i < a_nSubdivisions; i++)
	{
		// Draw the "Bottom" of the Cylinder
		AddTri(vector3(0.0f, 0.0f, -a_fHeight / 2),
			a_vBotPoints[(i + 1) % a_nSubdivisions],
			a_vBotPoints[i]);
		// Draw the Center of the Cylinder
		AddQuad(a_vBotPoints[i],
			a_vBotPoints[(i + 1) % a_nSubdivisions],
			a_vTopPoints[i],
			a_vTopPoints[(i + 1) % a_nSubdivisions]);
		// Draw the "Top" of the Cylinder
		AddTri(vector3(0.0f, 0.0f, a_fHeight / 2),
			a_vTopPoints[i],
			a_vTopPoints[(i + 1) % a_nSubdivisions]);

	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
//--- Completed ---//
void MyMesh::GenerateTube(float a_fOuterRadius, float a_fInnerRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fOuterRadius < 0.01f)
		a_fOuterRadius = 0.01f;

	if (a_fInnerRadius < 0.005f)
		a_fInnerRadius = 0.005f;

	if (a_fInnerRadius > a_fOuterRadius)
		std::swap(a_fInnerRadius, a_fOuterRadius);

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code
	//GenerateCube(a_fOuterRadius * 2.0f, a_v3Color);
	std::vector<vector3> a_vBotOuterPoints, a_vTopOuterPoints, a_vBotInnerPoints, a_vTopInnerPoints;
	float a_fPointIncrement = (2 * PI) / a_nSubdivisions;
	float a_fAngle = 0;
	for (int x = 0; x < a_nSubdivisions; x++)
	{
		float r = cos(a_fAngle);
		float k = sin(a_fAngle);
		// The division by 2 ensures that the axis of rotation is around the CENTER of the object, not around its bottom point
		// Grab the outer points
		a_vBotOuterPoints.push_back(vector3(a_fOuterRadius * r, a_fOuterRadius * k, -a_fHeight / 2));
		a_vTopOuterPoints.push_back(vector3(a_fOuterRadius * r, a_fOuterRadius * k, a_fHeight / 2));
		// Grab the inner points
		a_vBotInnerPoints.push_back(vector3(a_fInnerRadius * r, a_fInnerRadius * k, -a_fHeight / 2));
		a_vTopInnerPoints.push_back(vector3(a_fInnerRadius * r, a_fInnerRadius * k, a_fHeight / 2));
		a_fAngle += a_fPointIncrement;
	}

	for (int i = 0; i < a_nSubdivisions; i++)
	{
		// Draw the Top of the Tube
		AddQuad(a_vTopInnerPoints[(i + 1) % a_nSubdivisions],
			a_vTopInnerPoints[i],
			a_vTopOuterPoints[(i + 1) % a_nSubdivisions],
			a_vTopOuterPoints[i]);
		// Draw the Bottom of the Tube
		AddQuad(a_vBotInnerPoints[i],
			a_vBotInnerPoints[(i + 1) % a_nSubdivisions],
			a_vBotOuterPoints[i],
			a_vBotOuterPoints[(i + 1) % a_nSubdivisions]);

		// Draw the Center of the Tube on the OUTSIDE
		AddQuad(a_vBotOuterPoints[i],
			a_vBotOuterPoints[(i + 1) % a_nSubdivisions],
			a_vTopOuterPoints[i],
			a_vTopOuterPoints[(i + 1) % a_nSubdivisions]);
		// Draw the center of the Tube on the INSIDE
		AddQuad(a_vBotInnerPoints[(i + 1) % a_nSubdivisions],
			a_vBotInnerPoints[i],
			a_vTopInnerPoints[(i + 1) % a_nSubdivisions],
			a_vTopInnerPoints[i]);

	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
//--- Completed ---//
void MyMesh::GenerateTorus(float a_fOuterRadius, float a_fInnerRadius, int a_nSubdivisionsA, int a_nSubdivisionsB, vector3 a_v3Color)
{
	if (a_fOuterRadius < 0.01f)
		a_fOuterRadius = 0.01f;

	if (a_fInnerRadius < 0.005f)
		a_fInnerRadius = 0.005f;

	if (a_fInnerRadius > a_fOuterRadius)
		std::swap(a_fInnerRadius, a_fOuterRadius);

	if (a_nSubdivisionsA < 3)
		a_nSubdivisionsA = 3;
	if (a_nSubdivisionsA > 360)
		a_nSubdivisionsA = 360;

	if (a_nSubdivisionsB < 3)
		a_nSubdivisionsB = 3;
	if (a_nSubdivisionsB > 360)
		a_nSubdivisionsB = 360;

	Release();
	Init();

	// Replace this with your code
	//GenerateCube(a_fOuterRadius * 2.0f, a_v3Color);
	float a_fTubeOuterRadius = (a_fOuterRadius - a_fInnerRadius) / 2;
	float a_fTubeInnerRadius = a_fTubeOuterRadius + a_fInnerRadius;

	float a_fPointIncrementA = 2 * PI / a_nSubdivisionsA;

	for (uint i = 0; i < a_nSubdivisionsA; i++) {
		float a_fCurrentTorusAngle = a_fPointIncrementA * i;
		float a_fNextTorusAngle = a_fPointIncrementA * (i + 1);

		for (uint j = 0; j < a_nSubdivisionsB; j++) {
			float a_fCurrentTubeAngle = a_fPointIncrementA * j;
			float a_fNextTubeAngle = a_fPointIncrementA * (j + 1);

			vector3 a_vCurrentTorus = vector3((a_fTubeInnerRadius + a_fTubeOuterRadius * cosf(a_fCurrentTubeAngle)) * cosf(a_fCurrentTorusAngle),
				(a_fTubeInnerRadius + a_fTubeOuterRadius * cosf(a_fCurrentTubeAngle)) * sinf(a_fCurrentTorusAngle),
				a_fTubeOuterRadius * sinf(a_fCurrentTubeAngle));

			vector3 a_vCurrentTube = vector3((a_fTubeInnerRadius + a_fTubeOuterRadius * cosf(a_fNextTubeAngle)) * cosf(a_fCurrentTorusAngle),
				(a_fTubeInnerRadius + a_fTubeOuterRadius * cosf(a_fNextTubeAngle)) * sinf(a_fCurrentTorusAngle),
				a_fTubeOuterRadius * sinf(a_fNextTubeAngle));
			

			vector3 a_vNextTorus = vector3((a_fTubeInnerRadius + a_fTubeOuterRadius * cosf(a_fCurrentTubeAngle)) * cosf(a_fNextTorusAngle),
				(a_fTubeInnerRadius + a_fTubeOuterRadius * cosf(a_fCurrentTubeAngle)) * sinf(a_fNextTorusAngle),
				a_fTubeOuterRadius * sinf(a_fCurrentTubeAngle));

			vector3 a_vNextTube = vector3((a_fTubeInnerRadius + a_fTubeOuterRadius * cosf(a_fNextTubeAngle)) * cosf(a_fNextTorusAngle),
				(a_fTubeInnerRadius + a_fTubeOuterRadius * cosf(a_fNextTubeAngle)) * sinf(a_fNextTorusAngle),
				a_fTubeOuterRadius * sinf(a_fNextTubeAngle));
			
			AddQuad(a_vNextTorus, a_vNextTube, a_vCurrentTorus, a_vCurrentTube);
		}
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
//--- Completed ---//
void MyMesh::GenerateSphere(float a_fRadius, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	//Sets minimum and maximum of subdivisions
	if (a_nSubdivisions < 1)
	{
		GenerateCube(a_fRadius * 2.0f, a_v3Color);
		return;
	}

	if (a_nSubdivisions > 6)
		a_nSubdivisions = 6;

	Release();
	Init();

	// Replace this with your code
	//GenerateCube(a_fRadius * 2.0f, a_v3Color);
	vector3 a_vBottom = vector3(0, 0, -a_fRadius);
	vector3 a_vTop = vector3(0, 0, 0);
	std::vector<std::vector<vector3> > a_vPoints;

	for (int i = 0; i < a_nSubdivisions; i++)
	{
		a_vPoints.push_back(std::vector<vector3>());
		double theta = i * PI / a_nSubdivisions;
		for (int j = -a_nSubdivisions; j < a_nSubdivisions; j++)
		{
			a_vPoints[i].push_back(a_vTop);
			double phi = j * 2 * PI / a_nSubdivisions;
			a_vPoints[i][j + a_nSubdivisions].x = a_fRadius * sin(theta) * cos(phi);
			a_vPoints[i][j + a_nSubdivisions].y = a_fRadius * sin(theta) * sin(phi);
			a_vPoints[i][j + a_nSubdivisions].z = a_fRadius * cos(theta);
		}
	}

	for (uint i = 1; i < a_nSubdivisions; i++)
	{
		for (uint j = 0; j <= a_nSubdivisions + 1; j++)
		{
			AddTri(a_vPoints[i][j], a_vPoints[i][j + 1], a_vPoints[i - 1][j]);
			AddTri(a_vPoints[i][j + 1], a_vPoints[i - 1][j + 1], a_vPoints[i - 1][j]);


			if (i == a_nSubdivisions - 1) AddTri(a_vPoints[i][j + 1], a_vPoints[i][j], a_vBottom);
		}
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::AddTri(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft)
{
	//C
	//| \
	//A--B
	//This will make the triangle A->B->C 
	AddVertexPosition(a_vBottomLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopLeft);
}
void MyMesh::AddQuad(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft, vector3 a_vTopRight)
{
	//C--D
	//|  |
	//A--B
	//This will make the triangle A->B->C and then the triangle C->B->D
	AddVertexPosition(a_vBottomLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopLeft);

	AddVertexPosition(a_vTopLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopRight);
}
void MyMesh::Init(void)
{
	m_bBinded = false;
	m_uVertexCount = 0;

	m_VAO = 0;
	m_VBO = 0;

	m_pShaderMngr = ShaderManager::GetInstance();
}
void MyMesh::Release(void)
{
	m_pShaderMngr = nullptr;

	if (m_VBO > 0)
		glDeleteBuffers(1, &m_VBO);

	if (m_VAO > 0)
		glDeleteVertexArrays(1, &m_VAO);

	m_lVertex.clear();
	m_lVertexPos.clear();
	m_lVertexCol.clear();
}
MyMesh::MyMesh()
{
	Init();
}
MyMesh::~MyMesh() { Release(); }
MyMesh::MyMesh(MyMesh& other)
{
	m_bBinded = other.m_bBinded;

	m_pShaderMngr = other.m_pShaderMngr;

	m_uVertexCount = other.m_uVertexCount;

	m_VAO = other.m_VAO;
	m_VBO = other.m_VBO;
}
MyMesh& MyMesh::operator=(MyMesh& other)
{
	if (this != &other)
	{
		Release();
		Init();
		MyMesh temp(other);
		Swap(temp);
	}
	return *this;
}
void MyMesh::Swap(MyMesh& other)
{
	std::swap(m_bBinded, other.m_bBinded);
	std::swap(m_uVertexCount, other.m_uVertexCount);

	std::swap(m_VAO, other.m_VAO);
	std::swap(m_VBO, other.m_VBO);

	std::swap(m_lVertex, other.m_lVertex);
	std::swap(m_lVertexPos, other.m_lVertexPos);
	std::swap(m_lVertexCol, other.m_lVertexCol);

	std::swap(m_pShaderMngr, other.m_pShaderMngr);
}
void MyMesh::CompleteMesh(vector3 a_v3Color)
{
	uint uColorCount = m_lVertexCol.size();
	for (uint i = uColorCount; i < m_uVertexCount; ++i)
	{
		m_lVertexCol.push_back(a_v3Color);
	}
}
void MyMesh::AddVertexPosition(vector3 a_v3Input)
{
	m_lVertexPos.push_back(a_v3Input);
	m_uVertexCount = m_lVertexPos.size();
}
void MyMesh::AddVertexColor(vector3 a_v3Input)
{
	m_lVertexCol.push_back(a_v3Input);
}
void MyMesh::CompileOpenGL3X(void)
{
	if (m_bBinded)
		return;

	if (m_uVertexCount == 0)
		return;

	CompleteMesh();

	for (uint i = 0; i < m_uVertexCount; i++)
	{
		//Position
		m_lVertex.push_back(m_lVertexPos[i]);
		//Color
		m_lVertex.push_back(m_lVertexCol[i]);
	}
	glGenVertexArrays(1, &m_VAO);//Generate vertex array object
	glGenBuffers(1, &m_VBO);//Generate Vertex Buffered Object

	glBindVertexArray(m_VAO);//Bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);//Bind the VBO
	glBufferData(GL_ARRAY_BUFFER, m_uVertexCount * 2 * sizeof(vector3), &m_lVertex[0], GL_STATIC_DRAW);//Generate space for the VBO

	// Position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(vector3), (GLvoid*)0);

	// Color attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(vector3), (GLvoid*)(1 * sizeof(vector3)));

	m_bBinded = true;

	glBindVertexArray(0); // Unbind VAO
}
void MyMesh::Render(matrix4 a_mProjection, matrix4 a_mView, matrix4 a_mModel)
{
	// Use the buffer and shader
	GLuint nShader = m_pShaderMngr->GetShaderID("Basic");
	glUseProgram(nShader); 

	//Bind the VAO of this object
	glBindVertexArray(m_VAO);

	// Get the GPU variables by their name and hook them to CPU variables
	GLuint MVP = glGetUniformLocation(nShader, "MVP");
	GLuint wire = glGetUniformLocation(nShader, "wire");

	//Final Projection of the Camera
	matrix4 m4MVP = a_mProjection * a_mView * a_mModel;
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(m4MVP));
	
	//Solid
	glUniform3f(wire, -1.0f, -1.0f, -1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, m_uVertexCount);  

	//Wire
	glUniform3f(wire, 1.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.f, -1.f);
	glDrawArrays(GL_TRIANGLES, 0, m_uVertexCount);
	glDisable(GL_POLYGON_OFFSET_LINE);

	glBindVertexArray(0);// Unbind VAO so it does not get in the way of other objects
}
void MyMesh::GenerateCuboid(vector3 a_v3Dimensions, vector3 a_v3Color)
{
	Release();
	Init();

	vector3 v3Value = a_v3Dimensions * 0.5f;
	//3--2
	//|  |
	//0--1
	vector3 point0(-v3Value.x, -v3Value.y, v3Value.z); //0
	vector3 point1(v3Value.x, -v3Value.y, v3Value.z); //1
	vector3 point2(v3Value.x, v3Value.y, v3Value.z); //2
	vector3 point3(-v3Value.x, v3Value.y, v3Value.z); //3

	vector3 point4(-v3Value.x, -v3Value.y, -v3Value.z); //4
	vector3 point5(v3Value.x, -v3Value.y, -v3Value.z); //5
	vector3 point6(v3Value.x, v3Value.y, -v3Value.z); //6
	vector3 point7(-v3Value.x, v3Value.y, -v3Value.z); //7

	//F
	AddQuad(point0, point1, point3, point2);

	//B
	AddQuad(point5, point4, point6, point7);

	//L
	AddQuad(point4, point0, point7, point3);

	//R
	AddQuad(point1, point5, point2, point6);

	//U
	AddQuad(point3, point2, point7, point6);

	//D
	AddQuad(point4, point5, point0, point1);

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}