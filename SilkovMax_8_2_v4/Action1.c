Action1()
{
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
	  "Name=address1", "Value={Adress}", ENDITEM, 
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
 lr_think_time(4);
 
	return 0;
}
