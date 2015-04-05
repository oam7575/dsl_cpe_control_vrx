/* dsl_cpe_soap_Server.c
   Generated by gSOAP 2.7.8c from dsl_cpe_soap_interface.h
   Copyright (C) 2000-2006, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef _lint

#include "dsl_cpe_soap_H.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) dsl_cpe_soap_Server.c ver 2.7.8c 2007-03-23 15:33:32 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif

	do
	{
#ifdef WITH_FASTCGI
		if (FCGI_Accept() < 0)
		{
			soap->error = SOAP_EOF;
			return soap_send_fault(soap);
		}
#endif

		soap_begin(soap);

#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif

		if (soap_begin_recv(soap))
		{	if (soap->error < SOAP_STOP)
			{
#ifdef WITH_FASTCGI
				soap_send_fault(soap);
#else 
				return soap_send_fault(soap);
#endif
			}
			soap_closesock(soap);

			continue;
		}

		if (soap_envelope_begin_in(soap)
		 || soap_recv_header(soap)
		 || soap_body_begin_in(soap)
		 || soap_serve_request(soap)
		 || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ifx:DslCpeCliAccess"))
		return soap_serve_ifx__DslCpeCliAccess(soap);
	if (!soap_match_tag(soap, soap->tag, "ifx:DslCpeEventCallback"))
		return soap_serve_ifx__DslCpeEventCallback(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ifx__DslCpeCliAccess(struct soap *soap)
{	struct ifx__DslCpeCliAccess soap_tmp_ifx__DslCpeCliAccess;
	struct ifx__DslCpeCliAccessResponse soap_tmp_ifx__DslCpeCliAccessResponse;
	char * soap_tmp_xsd__string;
	soap_default_ifx__DslCpeCliAccessResponse(soap, &soap_tmp_ifx__DslCpeCliAccessResponse);
	soap_tmp_xsd__string = NULL;
	soap_tmp_ifx__DslCpeCliAccessResponse.result = &soap_tmp_xsd__string;
	soap_default_ifx__DslCpeCliAccess(soap, &soap_tmp_ifx__DslCpeCliAccess);
	soap->encodingStyle = "";
	if (!soap_get_ifx__DslCpeCliAccess(soap, &soap_tmp_ifx__DslCpeCliAccess, "ifx:DslCpeCliAccess", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ifx__DslCpeCliAccess(soap, soap_tmp_ifx__DslCpeCliAccess.command, &soap_tmp_xsd__string);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ifx__DslCpeCliAccessResponse(soap, &soap_tmp_ifx__DslCpeCliAccessResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ifx__DslCpeCliAccessResponse(soap, &soap_tmp_ifx__DslCpeCliAccessResponse, "ifx:DslCpeCliAccessResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ifx__DslCpeCliAccessResponse(soap, &soap_tmp_ifx__DslCpeCliAccessResponse, "ifx:DslCpeCliAccessResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ifx__DslCpeEventCallback(struct soap *soap)
{	struct ifx__DslCpeEventCallback soap_tmp_ifx__DslCpeEventCallback;
	struct ifx__DslCpeEventCallbackResponse soap_tmp_ifx__DslCpeEventCallbackResponse;
	char * soap_tmp_xsd__string;
	soap_default_ifx__DslCpeEventCallbackResponse(soap, &soap_tmp_ifx__DslCpeEventCallbackResponse);
	soap_tmp_xsd__string = NULL;
	soap_tmp_ifx__DslCpeEventCallbackResponse.result = &soap_tmp_xsd__string;
	soap_default_ifx__DslCpeEventCallback(soap, &soap_tmp_ifx__DslCpeEventCallback);
	soap->encodingStyle = "";
	if (!soap_get_ifx__DslCpeEventCallback(soap, &soap_tmp_ifx__DslCpeEventCallback, "ifx:DslCpeEventCallback", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ifx__DslCpeEventCallback(soap, soap_tmp_ifx__DslCpeEventCallback.command, &soap_tmp_xsd__string);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ifx__DslCpeEventCallbackResponse(soap, &soap_tmp_ifx__DslCpeEventCallbackResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ifx__DslCpeEventCallbackResponse(soap, &soap_tmp_ifx__DslCpeEventCallbackResponse, "ifx:DslCpeEventCallbackResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ifx__DslCpeEventCallbackResponse(soap, &soap_tmp_ifx__DslCpeEventCallbackResponse, "ifx:DslCpeEventCallbackResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#endif /* _lint*/

/* End of dsl_cpe_soap_Server.c */