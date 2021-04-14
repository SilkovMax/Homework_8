BuyTicket()
{

 tName = "03.OpenPage_ticket_FindFlight";
 lr_start_transaction(tName);
 
	  
	 status=web_url("Search Flights Button", 
	  "URL={Host}/cgi-bin/welcome.pl?page=search", 
	  "TargetFrame=body", 
	  "Resource=0", 
	  "RecContentType=text/html", 
	  "Referer={Host}/cgi-bin/nav.pl?page=menu&in=home", 
	  "Snapshot=t13.inf", 
	  "Mode=HTML", 
	  LAST);
 
 end_transaction(tName, status);
 //lr_think_time(4);
 
 tName = "04.Create_ticket_FindFlight";
 lr_start_transaction(tName);
 
	 web_reg_save_param_ex(
	    "ParamName=OFlight", 
	    "LB/IC=name=\"outboundFlight\" value=\"",
	    "RB/IC=\"",
	    "Ordinal=All",
	 LAST);
 
	 web_reg_save_param_ex(
	    "ParamName=BlueSkyNumber", 
	    "LB/IC=Blue Sky Air ",
	    "RB/IC=<td",
	    "Ordinal=1",
	 LAST);
 
 	web_reg_save_param_ex(
		"ParamName=Radio",
    	"LB=\"radio\" name=\"outboundFlight\" value=\"",
    	"RB=\"",
    	"Ordinal=All", 
		LAST);
 	
 web_reg_save_param_ex(
		"ParamName=priceTicket",
    	"LB=$ ",
    	"RB=<",
    	"Ordinal=All", 
		LAST);
 

 	
 
 
	

 status=web_submit_data("reservations.pl",
	  "Action={Host}/cgi-bin/reservations.pl", 
	  "Method=POST", 
	  "TargetFrame=", 
	  "RecContentType=text/html", 
	  "Referer={Host}/cgi-bin/reservations.pl?page=welcome", 
	  "Snapshot=t14.inf", 
	  "Mode=HTML", 
	  ITEMDATA, 
	  "Name=advanceDiscount", "Value=0", ENDITEM, 
	  "Name=depart", "Value={City1}", ENDITEM, 
	  "Name=departDate", "Value={Data1}", ENDITEM, 
	  "Name=arrive", "Value={City2}", ENDITEM, 
	  "Name=returnDate", "Value={Data2}", ENDITEM, 
	  "Name=numPassengers", "Value=1", ENDITEM, 
	  "Name=seatPref", "Value={SeatPref}", ENDITEM, 
	  "Name=seatType", "Value={TypePref}", ENDITEM, 
	  "Name=.cgifields", "Value=roundtrip", ENDITEM, 
	  "Name=.cgifields", "Value=seatType", ENDITEM, 
	  "Name=.cgifields", "Value=seatPref", ENDITEM, 
	  "Name=findFlights.x", "Value=51", ENDITEM, 
	  "Name=findFlights.y", "Value=11", ENDITEM, 
	  LAST);
 
 
  end_transaction(tName, status); 
  //lr_think_time(4);
  
 

 
 
// tName = "07.Itinerary";
// lr_start_transaction(tName);
// 
// web_reg_save_param_ex(
//    "ParamName=FlightID", 
//    "LB/IC=\"flightID\" value=\"",
//    "RB/IC=\"",
//    "Ordinal=all",
// LAST);
// 
//	 status=web_url("Itinerary Button", 
//	  "URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
//	  "TargetFrame=body", 
//	  "Resource=0", 
//	  "RecContentType=text/html", 
//	  "Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
//	  "Snapshot=t17.inf", 
//	  "Mode=HTML", 
//	  LAST);
// 
// end_transaction(tName, status); 
// //lr_think_time(4);
 
 return 0;
}
