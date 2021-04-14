vuser_end()
{
 tName = "9.Log_out";
 lr_start_transaction(tName);
 
	 status=web_url("SignOff Button", 
	  "URL={Host}/cgi-bin/welcome.pl?signOff=1", 
	  "TargetFrame=body", 
	  "Resource=0", 
	  "RecContentType=text/html", 
	  "Referer={Host}/cgi-bin/nav.pl?page=menu&in=itinerary", 
	  "Snapshot=t20.inf", 
	  "Mode=HTML", 
	  LAST);
 
 end_transaction(tName, status); 
 //lr_think_time(4);
 
	return 0;
}
