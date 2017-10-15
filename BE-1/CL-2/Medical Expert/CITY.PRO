domains											
    Destination,facts = symbol
    Traveller,name = string
predicates
    hypothesis(string,Destination)
    query(name,facts)
    response(char)
    go
clauses
    go :-
        write(" What is the traveller's name? "),
	readln(Traveller),
        hypothesis(Traveller,Destination),
        write(Traveller," may like to visit ",Destination,"."),nl.
    go :-
        write("Sorry, I don't seem to be able to suggest any holiday destination at present."),nl.
    query(Traveller,sightseeing) :-
        write("Does ",Traveller," like Sightseeing (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,riverrafting) :-
        write("Does ",Traveller," loves River Rafting (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,waterfalltrek) :-
        write("Does ",Traveller," like Waterfall trek (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,pubs) :-
        write("Does ",Traveller," like Pubs and Drinks (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,churches) :-
        write("Does ",Traveller," like to visit Churches(y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,iceskating) :-
        write("Does ",Traveller," like Natural Ice-Skating (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,coolclimate) :-
        write("Does ",Traveller," like Pleasant and Cool climate (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,snowhill) :-
        write("Does ",Traveller," like Snowy places and Hills (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,southfood) :-
        write("Does ",Traveller," like South-Indian food (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,temples) :-
        write("Does ",Traveller," like to visit temples (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,lakes) :-
        write("Does ",Traveller," like Lakes and Waterfalls (y/n) ?"),
        response(Reply),
        Reply='y'.
    query(Traveller,hillstation) :-
    	write("Does ",Traveller," like Hillstations (y/n) ?"),
    	response(Reply),
    	Reply='y'.
    hypothesis(Traveller,"Goa") :-
        query(Traveller,sightseeing),
        query(Traveller,riverrafting),
        query(Traveller,waterfalltrek),
        query(Traveller,pubs),
        query(Traveller,churches).
    hypothesis(Traveller,"Shimla") :-
        query(Traveller,iceskating),
        query(Traveller,coolclimate),
        query(Traveller,snowhill),
        query(Traveller,sightseeing).
    hypothesis(Traveller,"Kerala") :-
        query(Traveller,temples),
        query(Traveller,southfood),
        query(Traveller,sightseeing).    
    hypothesis(Traveller,"Shillong") :-
        query(Traveller,hillstation),
        query(Traveller,lakes),
        query(Traveller,sightseeing).
            
    response(Reply) :-
        readchar(Reply),
        write(Reply),nl.