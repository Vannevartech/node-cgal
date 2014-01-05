#include "NefPolyhedron2.h"
#include "cgal_args.h"

using namespace v8;
using namespace node;
using namespace std;


const char *NefPolyhedron2::Name = "NefPolyhedron2";


void NefPolyhedron2::RegisterMethods()
{
    NODE_DEFINE_CONSTANT(sConstructorTemplate, Nef_polyhedron_2::EXCLUDED);
    NODE_DEFINE_CONSTANT(sConstructorTemplate, Nef_polyhedron_2::INCLUDED);
    NODE_DEFINE_CONSTANT(sConstructorTemplate, Nef_polyhedron_2::EMPTY);
    NODE_DEFINE_CONSTANT(sConstructorTemplate, Nef_polyhedron_2::COMPLETE);
}


bool NefPolyhedron2::ParseArg(Local<Value> arg, Nef_polyhedron_2 &receiver)
{
    if (sConstructorTemplate->HasInstance(arg)) {

        // This supports e.g.: newnef = new CGAL.NefPolyhedron2(oldnef);

        receiver = ExtractWrapped(Local<Object>::Cast(arg));
        return true;

    } else {

        return false;

    }
}


Handle<Value> NefPolyhedron2::ToPOD(const Nef_polyhedron_2 &nef)
{
    HandleScope scope;
    Local<Object> obj = Object::New();
    return scope.Close(obj);
}


//----- Explicit instantiations here since we are a shared library:

template class CGALWrapper<NefPolyhedron2, Nef_polyhedron_2>;
