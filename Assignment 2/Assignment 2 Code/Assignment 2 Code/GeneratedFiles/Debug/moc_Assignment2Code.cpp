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
    QByteArrayData data[11];
    char stringdata0[153];
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
QT_MOC_LITERAL(6, 91, 22), // "TextBrowserOutputPrint"
QT_MOC_LITERAL(7, 114, 6), // "output"
QT_MOC_LITERAL(8, 121, 15), // "LabelImagePrint"
QT_MOC_LITERAL(9, 137, 11), // "QByteArray&"
QT_MOC_LITERAL(10, 149, 3) // "rgb"

    },
    "Assignment2Code\0PushButtonLoad\0\0"
    "PushButtonJPEGEncoder\0PushButtonJPEGDecoder\0"
    "PushButtonTest\0TextBrowserOutputPrint\0"
    "output\0LabelImagePrint\0QByteArray&\0"
    "rgb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Assignment2Code[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       8,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

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
        case 4: _t->TextBrowserOutputPrint((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->LabelImagePrint((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
