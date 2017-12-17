/**************************************************************************
 *
 *  Copyright 2015, 2017 Yuri Prokushev
 *
 *  This file is part of osFree project
 *
 *  This program is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or (at your
 *  option) any later version.
 * 
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 *  more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 */

#ifndef SOM_Module_scattrib_Source
#define SOM_Module_scattrib_Source
#endif

#define SOMTAttributeEntryC_Class_Source

#define __PRIVATE__
#include <rhbopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rhbsc.h"

#include "scattrib.xih"

SOM_Scope long SOMLINK somtSetSymbolsOnEntry(SOMTAttributeEntryC SOMSTAR somSelf,
	                                           /* in */ SOMTEmitC SOMSTAR emitter,
	                                           /* in */ string prefix)
{
  char buf[250];
  
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","somtSetSymbolsOnEntry");
  

  SOMTTemplateOutputC *templ = emitter->_get_somtTemplate();

  SOMTAttributeEntryC_parent_SOMTEntryC_somtSetSymbolsOnEntry(somSelf, emitter, prefix);
  RHBattribute *c=somSelf->_get_somtEntryStruct()->data->is_attribute();
  
  RHBtype *t=c->attribute_type->is_base_type();

  buf[0]=0;
  strcat(buf, prefix);
  templ->somtSetSymbolCopyBoth(strcat(buf, "BaseType"), c->attribute_type->id);

// ����� ���� ���������� �����������  
  return 1;
}

SOM_Scope SOMTMethodEntryC SOMSTAR SOMLINK somtGetFirstSetMethod(SOMTAttributeEntryC SOMSTAR somSelf)
{
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","somtGetFirstSetMethod");
  
  return NULL;
}

SOM_Scope SOMTEntryC SOMSTAR SOMLINK _get_somtAttribType(SOMTAttributeEntryC SOMSTAR somSelf)
{
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","_get_somtAttribType");

  return NULL;
}

SOM_Scope SOMTMethodEntryC SOMSTAR SOMLINK somtGetFirstGetMethod(SOMTAttributeEntryC SOMSTAR somSelf)
{
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","somtGetFirstGetMethod");
  
  return NULL;
}

SOM_Scope SOMTDataEntryC SOMSTAR SOMLINK somtGetFirstAttributeDeclarator(SOMTAttributeEntryC SOMSTAR somSelf)
{
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","somtGetFirstAttributeDeclarator");
  
  return NULL;
}

SOM_Scope SOMTMethodEntryC SOMSTAR SOMLINK somtGetNextGetMethod(SOMTAttributeEntryC SOMSTAR somSelf)
{
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","somtGetNextGetMethod");
  
  return NULL;
}

SOM_Scope SOMTDataEntryC SOMSTAR SOMLINK somtGetNextAttributeDeclarator(SOMTAttributeEntryC SOMSTAR somSelf)
{
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","somtGetNextAttributeDeclarator");
  
  return NULL;
}

SOM_Scope boolean SOMLINK _get_somtIsReadonly(SOMTAttributeEntryC SOMSTAR somSelf)
{
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","_get_somtIsReadonly");
  
  RHBattribute *c=somSelf->_get_somtEntryStruct()->data->is_attribute();
  
  return c->readonly;
}

SOM_Scope SOMTMethodEntryC SOMSTAR SOMLINK somtGetNextSetMethod(SOMTAttributeEntryC SOMSTAR somSelf)
{
  SOMTAttributeEntryCData *somThis = SOMTAttributeEntryCGetData(somSelf);
  SOMTAttributeEntryCMethodDebug("SOMTAttributeEntryC","somtGetNextSetMethod");
  
  return NULL;
}
