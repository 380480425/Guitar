#ifndef FILEDIFFWIDGET_H
#define FILEDIFFWIDGET_H

#include <QScrollBar>
#include <QWidget>
#include "Git.h"
#include "MainWindow.h"

class FileDiffSliderWidget;

class FileDiffWidget : public QWidget
{
	Q_OBJECT
private:
	QScrollBar *vertical_scroll_bar = nullptr;
	ViewType view_type = ViewType::None;

	DiffWidgetData::DiffData *diffdata();
	const DiffWidgetData::DiffData *diffdata() const;
	DiffWidgetData::DrawData *drawdata();
	const DiffWidgetData::DrawData *drawdata() const;
public:
	explicit FileDiffWidget(QWidget *parent);
	~FileDiffWidget();

	void update(ViewType vt);

protected:
	void paintEvent(QPaintEvent *);
	void wheelEvent(QWheelEvent *);
	void resizeEvent(QResizeEvent *);
	void contextMenuEvent(QContextMenuEvent *);
signals:
	void scrollByWheel(int lines);
	void resized();
};

#endif // FILEDIFFWIDGET_H
