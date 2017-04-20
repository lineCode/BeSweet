/**
/*   Copyright (c) 2003by  Marco Welti
/*
/*   This document is  bound by the  QT Public License
/*   (http://www.trolltech.com/licenses/qpl.html).
/*   See License.txt for more information.
/*
/*
/*
/*   ALL RIGHTS RESERVED.  
/* 
/*   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
/*   OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
/*   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/*   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
/*   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
/*   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
/*   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/*   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
/*   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
/*   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
/*   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
/* 
/***********************************************************************/

#include "stdafx.h"

#include "CTagsMethodLoader.h"

#include <Model/CTags/CTagsDatabase.h>
#include <Model/CTags/CTagsMetaObjectFactory.h>

using namespace std;
using CTags::Database::TagTable;

namespace CTags {

MethodLoader::MethodLoader(const smart_ptr<Workspace> &wspace)
: mDB(DatabaseManager::instance().getDatabase(wspace))
{
}
  
list<smart_ptr<Function> > MethodLoader::load()
{    
  TagTable tags = mDB->selectTagsWhere(make_query(TypeIs(), eFunction | eMethod));

  list<smart_ptr<Function> > methods;
  transform(tags.begin(), tags.end(), inserter(methods, methods.end()), FunctionInfoFactory());
  return methods;
}

} //namespace CTags