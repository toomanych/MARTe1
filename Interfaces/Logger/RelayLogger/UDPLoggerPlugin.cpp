/*
 * Copyright 2011 EFDA | European Fusion Development Agreement
 *
 * Licensed under the EUPL, Version 1.1 or - as soon they 
   will be approved by the European Commission - subsequent  
   versions of the EUPL (the "Licence"); 
 * You may not use this work except in compliance with the 
   Licence. 
 * You may obtain a copy of the Licence at: 
 *  
 * http://ec.europa.eu/idabc/eupl
 *
 * Unless required by applicable law or agreed to in 
   writing, software distributed under the Licence is 
   distributed on an "AS IS" basis, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either 
   express or implied. 
 * See the Licence for the specific language governing 
   permissions and limitations under the Licence. 
 *
 * $Id$
 *
**/
#include "UDPLoggerPlugin.h"
#include "LoggerMessage.h"
#include "ObjectMacros.h"


OBJECTLOADREGISTER(UDPLoggerPlugin, "$Id: UDPLoggerPlugin.cpp,v 1.1 2008/03/31 14:41:10 aneto Exp $")     
               
void UDPLoggerPluginReceiver(void *args){
    UDPLoggerPlugin *plugin = (UDPLoggerPlugin *)args;
    
    while(plugin->alive){        
        GCRTemplate<LoggerMessage> gcrlm = plugin->loggerMessageQ.Get();        
        if(gcrlm.IsValid()){
            plugin->ProcessMessage(gcrlm);
        }
    }        
}
