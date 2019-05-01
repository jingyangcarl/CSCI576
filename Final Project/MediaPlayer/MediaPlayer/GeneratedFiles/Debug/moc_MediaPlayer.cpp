/****************************************************************************
** Meta object code from reading C++ file 'MediaPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MediaPlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MediaPlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MediaPlayer_t {
    QByteArrayData data[11];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayer_t qt_meta_stringdata_MediaPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MediaPlayer"
QT_MOC_LITERAL(1, 12, 14), // "PushButtonLoad"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "PushButtonPlay"
QT_MOC_LITERAL(4, 43, 14), // "PushButtonStop"
QT_MOC_LITERAL(5, 58, 16), // "PushButtonReplay"
QT_MOC_LITERAL(6, 75, 15), // "LabelImagePrint"
QT_MOC_LITERAL(7, 91, 11), // "QByteArray&"
QT_MOC_LITERAL(8, 103, 9), // "frameData"
QT_MOC_LITERAL(9, 113, 10), // "frameIndex"
QT_MOC_LITERAL(10, 124, 20) // "UpdateVariableStatus"

    },
    "MediaPlayer\0PushButtonLoad\0\0PushButtonPlay\0"
    "PushButtonStop\0PushButtonReplay\0"
    "LabelImagePrint\0QByteArray&\0frameData\0"
    "frameIndex\0UpdateVariableStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       6,    2,   56,    2, 0x0a /* Public */,
      10,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void,

       0        // eod
};

void MediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MediaPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PushButtonLoad(); break;
        case 1: _t->PushButtonPlay(); break;
        case 2: _t->PushButtonStop(); break;
        case 3: _t->PushButtonReplay(); break;
        case 4: _t->LabelImagePrint((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->LabelImagePrint((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->UpdateVariableStatus(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MediaPlayer::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MediaPlayer.data,
    qt_meta_data_MediaPlayer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
