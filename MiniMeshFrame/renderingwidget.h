#ifndef RENDERINGWIDGET_H
#define RENDERINGWIDGET_H

#include <QGLWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QColorDialog>
#include <QFileDialog>

#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QTextCodec>

#include "SparseReconstruction\OptMeshInit.h"
#include "SparseReconstruction\SparseEncodingSolver.h"
#include "SparseReconstruction\DictionaryUpdate.h"

#include "SparseReconstruction\TriMesh.h"
#include "HE_mesh\Vec.h"

using trimesh::vec;
using trimesh::point;

class MainWindow;
class CArcBall;
class Mesh3D;

class RenderingWidget : public QGLWidget
{
	Q_OBJECT

public:
	RenderingWidget(QWidget *parent, MainWindow* mainwindow=0);
	~RenderingWidget();

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
	void timerEvent(QTimerEvent *e);

	// mouse events
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
	void wheelEvent(QWheelEvent *e);

public:
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent(QKeyEvent *e);

signals:
	void meshInfo(int, int, int);
	void operatorInfo(QString);

private:
	void Render();
	void SetLight();

	public slots:
	void SetBackground();
	void ReadMesh();
	void WriteMesh();
	void LoadTexture();
	void QuickTest();
	void TopoUpdateTest();
	void DictUpdateTest();

	void CheckDrawPoint(bool bv);
	void CheckDrawEdge(bool bv);
	void CheckDrawFace(bool bv);
	void CheckLight(bool bv);
	void CheckDrawTexture(bool bv);
	void CheckDrawAxes(bool bv);
	

private:
	void DrawAxes(bool bv);
	void DrawPoints(bool);
	void DrawEdge(bool);
	void DrawFace(bool);
	void DrawTexture(bool);
	void normalize(TriMesh &);

public:
	MainWindow					*ptr_mainwindow_;
	CArcBall					*ptr_arcball_;
	TriMesh						ptr_mesh_;
	OptMeshInit					*test_init_;
	bool						is_init_initialized_;
	std::vector<TriProj::Triangle> temp_;
	// Texture
	GLuint						texture_[1];
	bool						is_load_texture_;

	// eye
	GLfloat						eye_distance_;
	point						eye_goal_;
	vec							eye_direction_;
	QPoint						current_position_;

	// Render information
	bool						is_draw_point_;
	bool						is_draw_edge_;
	bool						is_draw_face_;
	bool						is_draw_texture_;
	bool						has_lighting_;
	bool						is_draw_axes_;

private:
	
};
#endif // RENDERINGWIDGET_H
