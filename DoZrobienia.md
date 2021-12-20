

#############################################
obczaić jak działa dziedziczenie dokładnie
Dokończyc renderowanie w entity i zrobić dziediczenie w player : entity
Przetestować renderując playera z texturą tank'a w oknie







piłki

// making vector of point objects
    std::vector<point::Point> points;

    // małe punkty mają być większe.

    for(int i = 0; i<100; i++){
        int rand_radius = randomRangefloat(2, 5);
        float rand_speed_X = randomRangefloat(-4, 4);
        float rand_speed_Y = randomRangefloat(-4, 4);
        int randColor[] = randomRGB;
        point::Point pt(SC_WIDTH/2, SC_HEIGHT/2, rand_radius, rand_speed_X, rand_speed_Y, randColor);
        points.push_back(pt);
    }

/* masa pilek
        ******************/
        // Handle ball hiting the bottom etc. logika jak zmiana kierunku ruchu itd.
        // many balls
        // for (point::Point& p: points) {
        //     p.update(dt);
        //     sf::FloatRect ballPos = p.getPos();
        
        //     if ( ((p.getPos().left+2*p.getRadius()) > SC_WIDTH) || (p.getPos().left < 0) ) {
        //         p.reboundSide(); 
        //     } else if ( ((p.getPos().top+2*p.getRadius()) > SC_HEIGHT) || (p.getPos().top < 0) ) {
        //         p.reboundTopBot();
        //     }
        // }


/* masa pilek
        ******************/
        // for (point::Point& p: points){
        //     window.draw(p.getShape());
        // }
        /******************/