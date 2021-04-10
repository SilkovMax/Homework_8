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
	    "Ordinal=1",
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
  
 
 tName = "05.Create_ticket_ChooseCost";
 lr_start_transaction(tName);
 
	 status=web_submit_data("reservations.pl_2", 
	  "Action={Host}/cgi-bin/reservations.pl", 
	  "Method=POST", 
	  "TargetFrame=", 
	  "RecContentType=text/html", 
	  "Referer={Host}/cgi-bin/reservations.pl", 
	  "Snapshot=t15.inf", 
	  "Mode=HTML", 
	  ITEMDATA, 
	  "Name=outboundFlight", "Value={OFlight}", ENDITEM, 
	  "Name=numPassengers", "Value=1", ENDITEM, 
	  "Name=advanceDiscount", "Value=0", ENDITEM, 
	  "Name=seatType", "Value={TypePref}", ENDITEM, 
	  "Name=seatPref", "Value={SeatPref}", ENDITEM, 
	  "Name=reserveFlights.x", "Value=73", ENDITEM, 
	  "Name=reserveFlights.y", "Value=13", ENDITEM, 
	  LAST);
 
 end_transaction(tName, status); 
 //lr_think_time(3);
 
 /* cont */
 tName = "06.Create_ticket_PaymentDetail";
 lr_start_transaction(tName);
 
	 status=web_submit_data("reservations.pl_3", 
	  "Action={Host}/cgi-bin/reservations.pl", 
	  "Method=POST", 
	  "TargetFrame=", 
	  "RecContentType=text/html", 
	  "Referer={Host}/cgi-bin/reservations.pl", 
	  "Snapshot=t16.inf", 
	  "Mode=HTML", 
	  ITEMDATA, 
	  "Name=firstName", "Value={FirstName}", ENDITEM, 
	  "Name=lastName", "Value={LastName}", ENDITEM, 
	  "Name=address1", "Value={Addres}", ENDITEM, 
	  "Name=address2", "Value={City}", ENDITEM, 
	  "Name=pass1", "Value={FirstName} {LastName}", ENDITEM, 
	  "Name=creditCard", "Value={Card}", ENDITEM, 
	  "Name=expDate", "Value={CardDate}", ENDITEM, 
	  "Name=oldCCOption", "Value=", ENDITEM, 
	  "Name=numPassengers", "Value=1", ENDITEM, 
	  "Name=seatType", "Value={TypePref}", ENDITEM, 
	  "Name=seatPref", "Value={SeatPref}", ENDITEM, 
	  "Name=outboundFlight", "Value={OFlight}", ENDITEM, 
	  "Name=advanceDiscount", "Value=0", ENDITEM, 
	  "Name=returnFlight", "Value=", ENDITEM, 
	  "Name=JSFormSubmit", "Value=off", ENDITEM, 
	  "Name=.cgifields", "Value=saveCC", ENDITEM, 
	  "Name=buyFlights.x", "Value=69", ENDITEM, 
	  "Name=buyFlights.y", "Value=2", ENDITEM, 
	  LAST);
 
 end_transaction(tName, status); 
 //lr_think_time(4);
 
 tName = "07.Itinerary";
 lr_start_transaction(tName);
 
 web_reg_save_param_ex(
    "ParamName=FlightID", 
    "LB/IC=\"flightID\" value=\"",
    "RB/IC=\"",
    "Ordinal=all",
 LAST);
 
	 status=web_url("Itinerary Button", 
	  "URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
	  "TargetFrame=body", 
	  "Resource=0", 
	  "RecContentType=text/html", 
	  "Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
	  "Snapshot=t17.inf", 
	  "Mode=HTML", 
	  LAST);
 
 end_transaction(tName, status); 
 //lr_think_time(4);
 
 return 0;
}
