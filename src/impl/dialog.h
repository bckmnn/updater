#ifndef UPDATER_IMPL_DIALOG_H
#define UPDATER_IMPL_DIALOG_H

#include <QtNetwork>
#include <QtWidgets>

#include "defaultupdater.h"

namespace updater {

class DownloadWidget : public QWidget {
    Q_OBJECT

public:
    DownloadWidget(const QString &message, QDialog *parent = 0);

public slots:
    void setProgress(int percent);
    void setErrorMessage(const QString &message);

private:
    QProgressBar *progressBar;
    QLabel *errorLabel;
};

class Dialog : public QDialog {
    Q_OBJECT

public:
    Dialog(DefaultUpdater *updater, QWidget *parent);

private:
    void showWidget(QWidget *widget);
    QWidget *setupDownloadWidget();
    QWidget *messageWidget();

    DefaultUpdater *updater;
    QStackedLayout *stackedLayout;
    DownloadWidget *downloadWidget;
};

} // namespace updater

#endif // UPDATER_IMPL_DIALOG_H
