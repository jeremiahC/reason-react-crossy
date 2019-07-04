module Player = {
    type t = {
        position: array(int)
    }
}

module Board = {
    type re = {
        ground: array(array(int))
    }
}

module Car = {
    type t = {
        position: list(array(int))
    }
}

module State = {
    type t =  {
        playerPosition: (int, int),
        carPost: (int, int),
        ground: array(array(int)),
        count: int
    }

    let initial_state = {
        playerPosition: (0, 0),
        carPost: (1, 0),
        ground: Array.make_matrix(15, 9, 0),
        count: 0
    }


    let changePoint = (point, axis, func) => {
        Js.log(0 <= point);
        switch (axis) {
        | "yaxis" => {
            if (point <= 0) {
                point + 1;
            } else if (point < 14) {
                func(point, 1)
            } else if (point == 14) {
                point - 1;
            } else {
                func(point, 0);
            }
        };
        | "xaxis" => {
            if (point <= 0) {
                point + 1;
            } else if (point < 8) {
                func(point, 1)
            } else if (point == 8) {
                point - 1;
            } else {
                func(point, 0);
            }
        };
        }
    };

    let reducer = (state, action) => {
        let (y, x) = state.playerPosition;
        let (car_y, car_x) = state.carPost;

        let new_state = switch (action) {
        | "up" => {
            state.ground[y][x] = 0;
            let y = changePoint(y, "yaxis", (-));
            {
                ...state,
                playerPosition: (y, x)
            }};
        | "down" => {
            state.ground[y][x] = 0;
            let y = changePoint(y, "yaxis", (+));
            {
                ...state,
                playerPosition: (y, x)
            }};
        | "left" => {
            state.ground[y][x] = 0;
            let x = changePoint(x, "xaxis", (-));
            {
                ...state,
                playerPosition: (y, x) 
            }};
        | "right" => {
            state.ground[y][x] = 0;
            let x = changePoint(x, "xaxis", (+));
            {
                ...state,
                playerPosition: (y, x)
            }};
        | "runCar" => {
            let count = state.count;

            state.ground[car_y][count] = 2;

            if (count != 0) {
                state.ground[car_y][count - 1] = 0;
                ();
            };
            {
                ...state,
                count: count < 8 ? count + 1 : 0 
            }
        };
        };

        new_state;
    }
}