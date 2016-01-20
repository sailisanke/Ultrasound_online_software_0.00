/****************************************************************************
** Meta object code from reading C++ file 'video_play.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../video_play.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_play.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Video_play_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Video_play_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Video_play_t qt_meta_stringdata_Video_play = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Video_play"
QT_MOC_LITERAL(1, 11, 14), // "updatePlayerUI"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "img"
QT_MOC_LITERAL(4, 31, 10), // "getFeature"
QT_MOC_LITERAL(5, 42, 20), // "on_loadVideo_clicked"
QT_MOC_LITERAL(6, 63, 20), // "on_playVideo_clicked"
QT_MOC_LITERAL(7, 84, 26) // "on_actionFeature_triggered"

    },
    "Video_play\0updatePlayerUI\0\0img\0"
    "getFeature\0on_loadVideo_clicked\0"
    "on_playVideo_clicked\0on_actionFeature_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Video_play[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    0,   45,    2, 0x08 /* Private */,
       6,    0,   46,    2, 0x08 /* Private */,
       7,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Video_play::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Video_play *_t = static_cast<Video_play *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePlayerUI((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->getFeature((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->on_loadVideo_clicked(); break;
        case 3: _t->on_playVideo_clicked(); break;
        case 4: _t->on_actionFeature_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject Video_play::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Video_play.data,
      qt_meta_data_Video_play,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Video_play::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Video_play::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Video_play.stringdata0))
        return static_cast<void*>(const_cast< Video_play*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Video_play::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
