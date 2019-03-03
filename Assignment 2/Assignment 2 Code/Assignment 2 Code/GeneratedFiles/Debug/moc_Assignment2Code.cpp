/****************************************************************************
** Meta object code from reading C++ file 'Assignment2Code.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Assignment2Code.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Assignment2Code.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Assignment2Code_t {
    QByteArrayData data[15];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Assignment2Code_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Assignment2Code_t qt_meta_stringdata_Assignment2Code = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Assignment2Code"
QT_MOC_LITERAL(1, 16, 14), // "PushButtonLoad"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "PushButtonJPEGEncoder"
QT_MOC_LITERAL(4, 54, 21), // "PushButtonJPEGDecoder"
QT_MOC_LITERAL(5, 76, 14), // "PushButtonTest"
QT_MOC_LITERAL(6, 91, 18), // "PushButtonShowDCTY"
QT_MOC_LITERAL(7, 110, 19), // "PushButtonShowDCTCr"
QT_MOC_LITERAL(8, 130, 19), // "PushButtonShowDCTCb"
QT_MOC_LITERAL(9, 150, 27), // "PushButtonShowOriginalImage"
QT_MOC_LITERAL(10, 178, 22), // "TextBrowserOutputPrint"
QT_MOC_LITERAL(11, 201, 6), // "output"
QT_MOC_LITERAL(12, 208, 15), // "LabelImagePrint"
QT_MOC_LITERAL(13, 224, 11), // "QByteArray&"
QT_MOC_LITERAL(14, 236, 3) // "rgb"

    },
    "Assignment2Code\0PushButtonLoad\0\0"
    "PushButtonJPEGEncoder\0PushButtonJPEGDecoder\0"
    "PushButtonTest\0PushButtonShowDCTY\0"
    "PushButtonShowDCTCr\0PushButtonShowDCTCb\0"
    "PushButtonShowOriginalImage\0"
    "TextBrowserOutputPrint\0output\0"
    "LabelImagePrint\0QByteArray&\0rgb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Assignment2Code[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x0a /* Public */,
      12,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void Assignment2Code::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Assignment2Code *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PushButtonLoad(); break;
        case 1: _t->PushButtonJPEGEncoder(); break;
        case 2: _t->PushButtonJPEGDecoder(); break;
        case 3: _t->PushButtonTest(); break;
        case 4: _t->PushButtonShowDCTY(); break;
        case 5: _t->PushButtonShowDCTCr(); break;
        case 6: _t->PushButtonShowDCTCb(); break;
        case 7: _t->PushButtonShowOriginalImage(); break;
        case 8: _t->TextBrowserOutputPrint((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->LabelImagePrint((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Assignment2Code::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Assignment2Code.data,
    qt_meta_data_Assignment2Code,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Assignment2Code::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Assignment2Code::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Assignment2Code.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Assignment2Code::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
